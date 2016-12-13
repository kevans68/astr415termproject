#include "nrutil.h"
#include "hw5.h"
#include <stdio.h> 



void leapfrog(float y[], float dydx[], int n, float x, float h, float yout[],void 
(*derivs)(float, float[],float []))
{
  int i;
 // float *vhalf; 
 // vhalf = vector(1,n/2);
  //printf("in: %f\t%f\n", y[1], y[2]);
  for (i=1; i<=n; i+=2)
  	{
    
   		 //advance v by half a time step 
    	y[i+1] = y[i+1] + .5*h*dydx[i+1];

    	//advance x by a full time step 
    	y[i] = y[i] + h*y[i+1];
	}
	
	(*derivs)(x,y,dydx);
	for (i=1; i<=n; i+=2)
	{
    	// advance v by a full time step 
    	yout[i+1] = y[i+1] + .5*h*dydx[i+1];
    	yout[i]=y[i];
    	//printf("out: %f\t%f\t%f\n", vhalf[i], yout[i], yout[i+1]);
    	//printf("out: %f\t%f\n", yout[i], yout[i+1]);
  }

}

 
 
 


