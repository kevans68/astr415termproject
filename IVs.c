#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <time.h>

/* 
double randR(double min, double max)
{
  return min + (double)(rand() / (double)(RAND_MAX) * (max - min));
}
 */

float randR(float min, float max)
{
  return min + (float) (rand() / (float) (RAND_MAX) * (max - min));
}

int main(int argc, char ** argv) 
{

if (argc != 2)
{
	printf("Usage: %s n \n",argv[0]);
    return 1;
}
    	

float x,y,z, N,p,V, M, psum, pbound, psqr, Msqr;
V = 4*6*3;
N = atoi(argv[1]);

srand(time(NULL));
int i = 1; 

psum = 0;
psqr = 0;
for(i=1; i<=N; i++)
{
	x = randR(0,3);
	y = randR(-1,3);
	z = randR(-3,3);
	
	//printf("%f %f %f \n",x,y,z);
	pbound = pow(x,2) + pow(y,2) + pow(z,2);
	p = 1+pow(x,2)+3*pow((y+z),2);
	
	if(pbound<=9) 
	{
		psum = psum + p; 
		psqr = psqr + pow(p,2);
	}
	
}

M = V*(psum/N);

Msqr = psqr/N;
float Mcalc = (psum/N);
M = V*Mcalc;
//float sigmaM =V*pow(sigmap,.5);
//printf("Mass of object: %f \n",M);

float sigmaM = V*pow(((Msqr-Mcalc)/N),.5);
//printf("Sigma of object: %f \n", sigmaM);

printf("%f %f %f \n",N,M,sigmaM);
return 0;
}