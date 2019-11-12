#include <math.h>
#include <complex.h>
#define PI 3.14159265358979323846
#include <stdio.h>

void FT(double (*x)[3], int len)
{
	double complex x_;
	int i;
	int j; 
	for(i=0;i<len;i++)
	{
		x_ = 0;
		for(j=0;j<len;j++)
		{
			x_ = x_ + *(*(x+j)+1) * cexp (- I * PI * 2 * i * j/(double) len); 
		}
		*(*(x + i) + 2)  = creal((1/ (double) len) * x_ * conj(x_)); 
	}
}
