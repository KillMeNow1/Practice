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
	double  dbl_a = 1.1, dbl_result = 0;

	char char_an_amino = 'a', char_another_amino = 'n';
	char *charArr_aminos_a = "ARNDCEQGHILKMFPSTWYV"; 
	char *charArr_aminos_b = "ARNDCEQGHILKMFPSTWY";
	char *charArr_aminos_c = "arndceqghilkmfpstwyv";



	/* Integer comparisons */

	/* Two simple tests for equality */
 	if(int_a == int_b)
	{	
		printf("\nValues %d and %d are equal\n", int_a, int_b);
	}
	if(int_a != int_b)
	{
		printf("\nValues %d and %d are not equal\n", int_a, int_b);
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


