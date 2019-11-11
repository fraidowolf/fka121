#include <stdio.h>
#include <math.h>
#include  <stdlib.h>
#include "header.h"
void assign_value(double *X, double value, int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		*(X+i)=value;
	}
}


void assign_matrix(double (*X)[3], double value, int len)
{
	int i;
	int j;
	for(j=0;j<3;j++)
	{
		for(i=0;i<len;i++)
		{
			*(X[j]+i)=value + i;
		}
	}
}

void print_vector(double X[], int len)
{
	int j;
	for(j=0;j<len;j++)
    {
        printf("%f\t",X[j]);
    }
}

void run1()
{
	int i;
	printf("len of array: ");
	scanf("%d", &i);
	printf("%d\n",i);

	/*
	double B[i];
	double A[i];
	double *ptr_B=&B[0];
	double *ptr_A=&A[0];
	*/

	double *ptr_A = malloc (i * sizeof (double));
	double *ptr_B = malloc (i * sizeof (double));

	assign_value(ptr_A,1,i);
	assign_value(ptr_B,2,i);

	double s = scalar_prod(ptr_A,ptr_B,i);
	printf("scalar prod: %f\n",s);

	free(ptr_A);
	free(ptr_B);
}

void run2()
{
	int i;
	printf("len of array: ");
	scanf("%d", &i);
	printf("%d\n",i);

	double B[i];
	double A[i];
	double *ptr_B=&B[0];
	double *ptr_A=&A[0];

	assign_value(ptr_A,1,i);
	assign_value(ptr_B,2,i);

	double s = scalar_prod(ptr_A,ptr_B,i);
	printf("scalar prod: %f\n",s);
}

void run3()                                                                                                   
{                                                                                                             
    int i;
	double s;	
    printf("len of nx3 matrix: ");                                                                                 
    scanf("%d", &i);                                                                                                                                                                               
           
	double  (*A)[3] = malloc(sizeof (double [3][i]));
    assign_matrix(A,1,i);
	s = calculate_distance(A,0,1);
	printf("distance: %f\n",s);	
	free(A);
} 

int main()
{
	run1();
	run2();
	run3();
	return 0;
}
