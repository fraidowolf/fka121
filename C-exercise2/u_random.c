#include  <gsl/gsl_rng.h>
#include <stdio.h>
#include <math.h>
#include  <stdlib.h>

void generate_rand_array(double *P, int len)
{

	int i;
	const  gsl_rng_type *T; /*  static  info  about  rngs */
	double u;
	gsl_rng *q; /* rng  instance  */
	gsl_rng_env_setup (); /*  setup  the  rngs */
	T = gsl_rng_default; /*  specify  default  rng */
	q = gsl_rng_alloc(T); /*  allocate  default  rng */
	gsl_rng_set(q,100); /*  Initialize  rng */

	for(i=0;i<len;i++)
	{ 
		u = gsl_rng_uniform(q);
		*(P + i) = u;

	}
	gsl_rng_free(q); /*  deallocate  rng */
}

void dump_rand_array(double *P, int len)
{
	int i;
	FILE *f = fopen("u_random.csv","w");
	for(i=1;i<len;i++)
	{
		fprintf(f,"%f\n",*(P + i));
	}
	fclose(f);
}

int main()
{
	int len = 1000;
	double *ptr = malloc (len * sizeof (double));
	generate_rand_array(ptr,len);
	dump_rand_array(ptr,len);
	free(ptr);
	return 0;
}
