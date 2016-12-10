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
  min + (float) (rand() / (float) (RAND_MAX) * (max - min));

}


int main(int argc, char ** argv) 
{

if (argc != 2)
{
	printf("Usage: %s n \n",argv[0]);
    return 1;
}
    	

// float x,y,z, N,p,V, M, psum, pbound, psqr, Msqr;
// V = 4*6*3;
// N = atoi(argv[1]);

srand(time(NULL));
int i = 1; 


for(i=1; i<=10; i++)
{
	float x = randR(0,3);
	float y = randR(-1,3);
	float z = randR(-3,3);
	

}

/* 
M = V*(psum/N);

Msqr = psqr/N;
float Mcalc = (psum/N);
M = V*Mcalc;
//float sigmaM =V*pow(sigmap,.5);
//printf("Mass of object: %f \n",M);

float sigmaM = V*pow(((Msqr-Mcalc)/N),.5);
//printf("Sigma of object: %f \n", sigmaM);

printf("%f %f %f \n",N,M,sigmaM);
 */
return 0;
}