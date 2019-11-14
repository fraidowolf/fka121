#include <math.h>
#define PI 3.14159265358979323846

void cos_f1(double (*x)[3], int len, double a, double f, double phi, double dt)
{
	int i;
	for(i=0;i<len;i++)
	{ 
		*(*(x + i) + 1) = a*cos(2*PI*f*((double) i*dt)+phi);
		*(*(x + i)) = i*dt;
	}
}


void cos_f4(double (*x)[3], 
		int len, 
		double a1, 
		double a2,
		double f1,
	   	double f2,
		double phi1,
		double phi2,
		double dt)
{
	int i;
	for(i=0;i<len;i++)
	{ 
		*(*(x + i) + 1) = a1*cos(2*PI*f1*((double) i*dt)+phi1) + 
						  a2*cos(2*PI*f2*((double) i*dt)+phi2);
		*(*(x + i)) = i*dt;
	}
}


