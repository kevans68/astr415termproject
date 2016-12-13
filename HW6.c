#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include "nrutil.h"
#include "nr.h"
#include "hw5.h" 

#define FREQ 	100
#define E 0 
#define STEPS 10000

int N = 0;
float *m;

void parrayf(float y[], int n){
  for(int j = 1; j <= n; j++)printf("%f ",y[j]); printf("\n");
}

void derivs(float t, float y[], float dydx[]) 
{

  float rx, ry, rz, rx_ji, ry_ji, rz_ji,r_ij,r_ji,G;
  int i,j;
  G = 1;
  
  for(i=1; i <= N; i++)
  {
    // Define velocities in 3D 
    // vx 
    dydx[1+(i-1)*6] = y[2+(i-1)*6];
    //vy
    dydx[3+(i-1)*6] = y[4+(i-1)*6];
    // vz 
    dydx[5+(i-1)*6] = y[6+(i-1)*6];
	
	 dydx[2+(i-1)*6] =0;
    
    dydx[4+(i-1)*6] = 0;
    
    dydx[6+(i-1)*6] = 0; 
    // Define accelerations in 3D 
    //for(j=1;j<i;j++)
    for(j=1;j<=N;j++)
    {
      if(j!=i)
      {
        // define r_ij components 
        // rx = x[i] - x[j]
        rx = y[1+(i-1)*6] - y[1+(j-1)*6];
        ry = y[3+(i-1)*6] - y[3+(j-1)*6];
        rz = y[5+(i-1)*6] - y[5+(j-1)*6];

        // rx_ji = y[1+(j-1)*6] - y[1+(i-1)*6];
//         ry_ji = y[3+(j-1)*6] - y[3+(i-1)*6];
//         rz_ji = y[5+(j-1)*6] - y[5+(i-1)*6];

        r_ij = pow((pow(rx,2) + pow(ry,2) + pow(rz,2)),.5);
        r_ji = -r_ij;

        
        //ax 
        // 
        // ax           = -G * m * dx * v / 
        dydx[2+(i-1)*6] +=-rx/fabs(pow((r_ij),3));

       // dydx[2+(i-1)*6] +=-rx/pow((r_ij +pow(E,2)),3/2);
        //ay 
        dydx[4+(i-1)*6] +=-ry/fabs(pow((r_ij),3));
        //dydx[4+(i-1)*6] +=-ry/pow((r_ij +pow(E,2)),3/2);

        //az 
        dydx[6+(i-1)*6] +=-rz/fabs(pow((r_ij),3));
		//dydx[6+(i-1)*6] +=-rz/pow((r_ij +pow(E,2)),3/2);

        // top of matrix 
        //ax 
        /* 
		dydx[2+(j-1)*6] +=(-G*m[i]*rx_ji*dydx[1+(j-1)*6])/pow((r_ji +pow(E,2)),3/2);
        //ay 
        dydx[4+(j-1)*6] +=(-G*m[i]*ry_ji*dydx[3+(j-1)*6])/pow((r_ji +pow(E,2)),3/2);
        //az 
        dydx[6+(j-1)*6] +=(-G*m[i]*rz_ji*dydx[5+(j-1)*6])/pow((r_ji +pow(E,2)),3/2);
 */
      }		

    }
   // printf("Returning dydx:");
    //parrayf(dydx,N*6);
  }
}




int main(int argc,char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: %s <inputfile> <timestep> <Number of particles>  \n",argv[0]);
    return 1;
  }

  char * filename = argv[1];
  FILE *file= fopen(filename, "r");

  if( file == NULL ){
    printf("Error opening file \"%s\"\n",filename);
    return 1;
  }

  float h = atof(argv[2]); 
  N = atof(argv[3]);
  //float P = atof(argv[4]);
  //float P = pow(10,10);
  //float P100 = (P)/h;
  float P100 =3.7/h;
  
  float * y; 
  y = vector(1,N*6);
  m = vector(1,N);


  // create a file to store data 
  char rk4_filename[20];
  sprintf(rk4_filename, "rk4_%f.dat",h);

  FILE* rk4_f = fopen(rk4_filename, "w");
  
  
char lf_filename[20];
  sprintf(lf_filename, "lf_%f.dat",h);

  FILE* lf_f = fopen(lf_filename, "w");
 


  // read in initial conditions 
  for(int i=1;i<=N;i++)
  {
    // read in initial conditions into y and m vectors  
    fscanf(file, "%f %f %f %f %f %f %f ",&m[i],&y[1+(i-1)*6],&y[2+(i-1)*6],&y[3+(i-1)*6],
        &y[4+(i-1)*6],&y[5+(i-1)*6],&y[6+(i-1)*6]);
    
  }

//RK4
  //start t from 0
  float t=0;
  //define vector dydx with N*6 elements 
    float * dydx = vector(1,N*6);
    int i = 0;
  // loop over particles starting with 1 STEPS times
  for(int i=1;i<=P100; i++)
	//for(int i=1;i<=P100; i++)
  {
    

    //define derivatives given the initial conditions
    derivs(t,y,dydx);

    //rk4 for each timestep 
    rk4(y,dydx,N*6,t,h,y,derivs);

    //  parrayf(y,N*6);

	if(i % FREQ == 0)
	{
		//printf("%d \n",i);
    	//print data to file: t,x1, vx1, y1, vy1, z2, vz1,x2, vx2, y2, vy2, z2, vz2
    	fprintf(rk4_f, "%f %f %f %f %f %f %f %f %f %f %f %f %f \n",t,y[1],y[2],
        		y[3],y[4],y[5],y[6],y[7],y[8],y[9],y[10],y[11],y[12]);
	}
    t = t+h;
  }

  fclose(rk4_f);
  
  fclose(file);
  FILE* file1 = fopen(filename, "r");
  
// y[1]= 0;
// y[2] =0;
// y[3]=0;
// y[4]=0;
// y[5]=0;
// y[6]=0;
// y[7]=0;
// y[8]=0;
// y[9]=0;
// y[10]=0;
// y[11]=0;
// y[12]=0;
  
  // reset initial conditions 
  for(int i=1;i<=N;i++)
  {
    // read in initial conditions into y and m vectors  
    fscanf(file, "%f %f %f %f %f %f %f ",&m[i],&y[1+(i-1)*6],&y[2+(i-1)*6],&y[3+(i-1)*6],
        &y[4+(i-1)*6],&y[5+(i-1)*6],&y[6+(i-1)*6]);
    
  }

  // Leapfrog 
  //start t from 0
	t=0;
	i = 0;
  // loop over particles starting with 1 STEPS times
  for(int i=1;i<=P100; i++)
  {

    //define derivatives given the initial conditions
    derivs(t,y,dydx);

    //rk4 for each timestep 
leapfrog(y, dydx, N*6, t, h, y, derivs);
  //  parrayf(y,N*6);
    
    if(i % FREQ)
    {
    	//printf("%d \n", i);
    	//print data to file: t,x1, vx1, y1, vy1, z2, vz1,x2, vx2, y2, vy2, z2, vz2
   		fprintf(lf_f, "%f %f %f %f %f %f %f %f %f %f %f %f %f \n",t,y[1],y[2],
   				 y[3],y[4],y[5],y[6],y[7],y[8],y[9],y[10],y[11],y[12]);
	}			
    t = t+h;
  }
  
    fclose(lf_f);
	fclose(file1);
	free_vector(y,1,N*6);
	free_vector(m,1,N);
	free_vector(dydx,1,N*6);


  return 0;
}

