#include <stdio.h>
#include <math.h>
#include  <stdlib.h>
#define PI 3.14159265358979323846
#include "fourier_transform.h"
#include "cos_functions.h"

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
	cos_f1(x, len, a, f, phi, dt);
	dump_3D_array(x, len, filename);
	free(x);

}


void calc_fft(int len)
{
	double  (*x)[3] = malloc(sizeof (double [len][3]));
	char const *filename = "./with_FT_N256.csv";  
	double f=2; 
	double phi=PI/2; 
	double dt=0.1; 
	double a=1;

	cos_f1(x,len,a,f,phi,dt);
	FT(x, len);
	dump_3D_array(x,len,filename);
	free(x);
}


void calc_fft2(int len)
{
	double  (*x)[3] = malloc(sizeof (double [len][3]));
	char const *filename = "./with_FT_cos_f4.csv";  
	double f1=2; 
	double phi1=0; 
	double dt=0.05; /* changed!! */ 
	double a1=1;
	double f2=6; 
	double phi2=0;  
	double a2=1;

	cos_f4(x,len,a1,a2,f1,f2,phi1,phi2,dt);
	FT(x, len);
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

	/* TASK 1.2 and 1.3 */
	calc_fft(256);

	/* TASK 1.4 */
	calc_fft2(250);


		

		

	return 0;
}
