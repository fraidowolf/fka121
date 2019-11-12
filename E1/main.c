#include <stdio.h>
#include <math.h>
#include  <stdlib.h>
#define PI 3.14159265358979323846
#include "fourier_transform.h"


void cos_func(double (*x)[3], int len, double a, double f, double phi, double dt)
{
	int i;
	for(i=0;i<len;i++)
	{ 
		*(*(x + i) + 1) = a*cos(2*PI*f*((double) i*dt)+phi);
		*(*(x + i)) = i*dt;
	}
}


void dump_3D_array(double (*x)[3], int len, char const *filename)
{
	int i;
	FILE *f = fopen(filename,"w");
	for(i=1;i<len;i++)
	{
		fprintf(f,"%f\t%f\t%f\n",*(*(x + i)), *(*(x + i) + 1), *(*(x + i)+2));
	}
	fclose(f);
}

void run_cos_func(char const *filename, 
				  int len, 
				  double f, 
				  double phi, 
				  double dt, 
				  double a)
{
	double (*x)[3] = malloc (sizeof (double[len][3]));
	cos_func (x, len, a, f, phi, dt);

	dump_3D_array(x, len, filename);
	free(x);

}

void calc_fft(int len)
{
	double  (*x)[3] = malloc(sizeof (double [len][3]));
	char const *filename = "./with_FT.csv";  
	double f=1; 
	double phi=0; 
	double dt=0.1; 
	double a=1;

	cos_func(x,len,a,f,phi,dt);
	FT(x, len);
	int i;
	dump_3D_array(x,len,filename);
	free(x);
}

int main()
{
	/* TASK 1.1 */
	char const *fname1 = "./cos_func1.csv";
	run_cos_func(fname1, 250, 2, 0, 0.1, 1);

	char const *fname2 = "./cos_func2.csv";
	run_cos_func(fname2, 250, 1, 0, 0.1, 1);
	
	char const *fname3 = "./cos_func3.csv";
	run_cos_func(fname3, 250, 1, PI/2, 0.1, 1);

	/* TASK 1.2 */
	calc_fft(250);

		

	return 0;
}
