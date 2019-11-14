#include <stdio.h>
#include <math.h>
#include  <stdlib.h>
#define PI 3.14159265358979323846
#include "fourier_transform.h"
#include "cos_functions.h"
#define N_PARTICLES 3

double pos_step(double p, double v, double dt)
{
	return p + v * dt + (1/2) * a * pow(dt,2);
}

double v_step_half(double v, double a, double dt)
{
	return v + (1/2)*a*dt;
}

double acc(double p)
{
	
}

double v_step(double v_half, double a, double dt)
{
	return v_half + (1/2)*a*dt;
}



void verlet(double (*p)[N_PARTICLES + 1], int len)
{

}


int main()
{
	int len = 250;
	double dt = 0.1;
	double  (*p)[N_PARTICLES + 1] = malloc(sizeof (double [len][N_PARTICLES + 1]));

	free(p);
	return 0;
}
