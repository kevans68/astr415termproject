#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <time.h>
#include "nrutil.h"
#include "nr.h"
#define SCALE 50
#define G1 .4
#define G2 .8
#define OS1 1 
#define OS2 -1

float randR(float min, float max)
{
  return min + (float) (rand() / (float) (RAND_MAX) * (max - min));
}


int main() 
{
  char xy[20];

 sprintf(xy,"xy.dat");

FILE* xy_f = fopen(xy, "w");
 float i;
 
 // cacluate 500 points within the circle of radius r
 float c=0;
 float j;

// radius of circle
	float r =1; 
	
// define density
	float A = M_PI*pow(r,2);
	float p_r = exp(-r);
	
// for(j=1;j<=2;j++)
//{
	 while(c<=499)
	 {
		// create Gaussian distibution of random points x and y 
		float u = randR(-1*SCALE,1*SCALE);
		float v = randR(-1*SCALE,1*SCALE);
		float x = sqrtf(-2*log(u))-1;
		float y = sqrtf(-2*log(v))-1;
	
		//calculate the area
		//float bound = (M_PI*pow(r,2))*SCALE;
		float bound = pow(x,2) + pow(y,2);
	
		// if the point is within the area of the circle the get other initial conditions 
		// and add to file initial conditions file. 
		if(bound<=r) 
		{
			float rcalc = pow(x,2) +pow(y,2);
			//float area = rcalc*M_PI;
		
			float z = G1*x;
		
			float vx = 0;
			float vz = 0 ;
			float vy = sqrtf(p_r*A/rcalc);
			fprintf(xy_f,"%f %f %f %f %f %f \n",x,vx,y,vy,z,vz);
			
			
			c =c+1;
	
		}
	  }
	//printf("%f \n",c);
//}
return 0;
}