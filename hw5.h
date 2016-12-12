#ifndef _HW5_H
#define _HW5_H
void eulerk(float y[], float dydx[], int n, float x, float h, float yout[]);

// void leapfrog(float y[], float dydx[], int n, float x, float h, float xvec[], float vvec[]);
//void leapfrog(float y[], float dydx[], int n, float x, float h, float yout[]);
void leapfrog(float y[], float dydx[], int n, float x, float h, float yout[],void 
(*derivs)(float, float[],float []));
#endif 
