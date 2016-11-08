/*
        A program to examine typed variables and
        mathematical operators
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        /* Variables we're going to use */
        int int_a = 1;
        int int_b = 2, int_c = 3;
        int int_result = 0;
        double  dbl_a = 1.1;
        double  dbl_b = 2.2, dbl_c = 3.3;
        double  dbl_result = 0;

        int_result = int_a+int_b;
        dbl_result =int_a/dbl_c;

        printf("Adding %d and %d", int_a, int_b);
        printf("results in %d \n", int_result);

        printf("Dividing %d by %f", int_a, dbl_c);
        printf("results in %f \n", dbl_result);

	exit(0);
}/* main */

