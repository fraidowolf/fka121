#include <stdio.h>
#include <math.h>
#include  <stdlib.h>

double scalar_prod(double *A,double *B, int len)
{
	double scalar_prod;
	int i;
	for(i=0;i<len;i++)
	{
		scalar_prod = scalar_prod + *(A+i) * *(B+1);	
	}

	return scalar_prod;
}


double calculate_distance(double (*X)[3], int point1, int point2)
{
	int i;
	double d;

	for(i=0;i<3;i++)
	{
		d = d + pow(*(X[i]+point1) - *(X[i]+point2),2);
	}

	d = sqrt(d);
	return d;
}


