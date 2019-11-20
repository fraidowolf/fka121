/* 	Program for use on part two on discrete Fourier transforms in E1 
	Created by Martin Gren on 2014-10-21
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "fft_func.h"
#define PI 3.141592653589
#define n 250 /*number of timesteps*/

int main ()
{
	/* timestep dt */
	double dt = 0.01;

	/* Declare and set Iteration parameter, data arrays and frequency */
	int i;
	double data[n];
	double freq[n];
	double powspec_data[n];
	double f = 2;
	double f_2 = 6; 
	double phi = 0;	

	/* declare file variables */
	FILE *file1;
	FILE *file2;	

	/* calculate data points */
	for (i = 0; i < n; i++)	{
		data[i] = cos(2*PI*f*dt*i+phi) + cos(i*2*PI*f_2*dt);
	}

	/*Save function values in file*/
	file1 = fopen("function_dt0,01.dat","w");
	for (i = 0; i < n; i++)	{
		fprintf (file1,"%e \t %e \n", i*dt, data[i]);
	}
	fclose(file1);

	/* make FFT (powerspectrum) */
	powerspectrum(data, powspec_data, n);
	powerspectrum_shift(powspec_data,n);
	fft_freq_shift(freq, dt, n);

	/*Save powerspectrum data in file */
  file2 = fopen("powerspectrum_dt0,01.dat","w");
	for (i = 0; i < n; i++)	{
		fprintf (file2,"%e \t %e\n", freq[i], powspec_data[i]);
	}
	
	fclose(file2);
	return 0;
}

