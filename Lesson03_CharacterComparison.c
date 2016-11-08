#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Lesson 03 Loops */
/* This file is CharacterComparison.c */

int main(int argc, char **argv)
{

	/* Declare variables */
	char *charArr_1D_stringA = "Bat";
	char *charArr_1D_stringB = "Cat";
	int int_stringA_length = (int) strlen(charArr_1D_stringA);
	int int_stringB_length = (int) strlen(charArr_1D_stringB);
	int int_i = 0;	
	int score = 0;	

	printf("A program to score characters in a string\n");


	for(int_i = 0; int_i < int_stringA_length; int_i++)
	{
		printf("Comparing %c with %c ",charArr_1D_stringA[int_i], charArr_1D_stringB[int_i]);

		if(charArr_1D_stringA[int_i] != charArr_1D_stringB[int_i])
		{
			score = score -1;
			printf(" Score is now %d \n", score);
		}
		else
		{
			score++;
			printf(" Score is now %d .\n", score);
		}/* if identical */
			
	}/* for int_stringA_length */

	exit(0);
}//main

