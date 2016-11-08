/*
        A program to examine comparison operators 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/* Variables we're going to use */
	int int_a = 1;
	int int_b = 2;
	double  dbl_a = 1.0, dbl_result = 0;
	double dbl_summation = 0;
	int q22 = 100;
	int q22_2 = 9;
	double result = 0;
	int remainder = 0;

	result = q22 / q22_2;
	remainder =  q22 % q22_2;
	printf("%f with remainder %d", result, remainder);

	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);
	dbl_summation = dbl_summation + 0.1;
	printf("\nResult is %f.\n", dbl_summation);

	char char_an_amino = 'a', char_another_amino = 'n';
	char *charArr_aminos_a = "ARNDCEQGHILKMFPSTWYV"; 
	char *charArr_aminos_b = "ARNDCEQGHILKMFPSTWY";
	char *charArr_aminos_c = "arndceqghilkmfpstwyv";



	/* Integer comparisons */

	/* Two simple tests for equality */
	if (dbl_summation == int_a)
	{
		printf("\nValues %f and %d are equal\n", 			dbl_summation, int_a);
	}
	if (dbl_summation != int_a)
	{
		printf("\nValues %f and %d are not equal\n", 			dbl_summation, int_a);
	}
 	if(int_a == dbl_a)
	{	
		printf("\nValues %d and %f are equal\n", int_a, dbl_a);
	}
	if(int_a != int_b)
	{
		printf("\nValues %d and %f are not equal\n", int_a, 			dbl_a);
	}/* if/else (int_a < int_b) */
	
	printf("------------------------\n");

	/* IF / ELSE test for equality */
 	if(int_a == int_b)
	{	
		printf("Values %d and %d are equal\n", int_a, int_b);
	}
	else	
	{
		printf("Values %d and %d are not equal\n", int_a, int_b);
	}/* if/else (int_a < int_b) */

	
	printf("------------------------\n");

	/* Floating-point comparisons */

	dbl_result = int_a * dbl_a;

	/* IF / ELSE IF / ELSE tests */
	if(dbl_a < dbl_result)
	{
		printf("%f is smaller than %f\n", dbl_a, dbl_result);
	}
	else if(dbl_a == dbl_result){
		printf("%f is equal to %f\n", dbl_a, dbl_result);
	}
	else
	{
		printf("%f is greater than %f\n", dbl_a, dbl_result);
	}/* if/else if/else (dbl_a < dbl_result) */
	

	printf("------------------------\n");

	/* Character Comparisons */

	if(char_an_amino == char_another_amino)
	{
		printf("Value %c and %c are the same\n", char_an_amino, char_another_amino);
	}
	else
	{
		printf("Values %c and %c are not the same\n", char_an_amino, char_another_amino);
	}
	

	printf("------------------------\n");
	

	if(char_an_amino > char_another_amino)
	{
		printf("Value %c is greater than %c\n", char_an_amino, char_another_amino);
	}
	else
	{
		printf("Value %c is less than or equal to %c\n", char_an_amino, char_another_amino);
	}

	
	printf("------------------------\n");

	/* String Comparisons */

	if(strcmp(charArr_aminos_a, charArr_aminos_b) == 0)
	{
		printf("%s is the same as %s\n", charArr_aminos_a, charArr_aminos_b);
	}
	else
	{
		printf("%s is NOT the same as %s\n", charArr_aminos_a, charArr_aminos_b);
	}

	
	printf("------------------------\n");
	printf("Done.\n");
	exit(0);

}/* main */


