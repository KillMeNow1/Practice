/*
        A program to examine typed variables and
        mathematical operators
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        /* Variables we're going to use */
        int int_a = 10;
        int int_b = 2, int_c = 3;
        int int_result = 0;
        double  dbl_a = 1.1;
        double  dbl_b = 2.2, dbl_c = 3.3;
	int dbl_result=0;
	double dbl_summation = 0;
        
        int_result = int_a+int_b;
     	dbl_result = (int)(10.0/3.3);
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;
	dbl_summation = dbl_summation+(float) 0.1;

	printf("Result is now %.16f.", dbl_summation);

        printf("Adding %d and %d", int_a, int_b);
        printf(" results in %d \n", int_result);

        printf("Dividing %d by %f", int_a, dbl_c);
        printf(" results in %d \n", dbl_result);

	exit(0);
}/* main */

