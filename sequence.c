#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Lesson 03 Loops */
/* This file is CharacterComparison.c */

int main(int argc, char **argv)
{

	/* Declare variables */
	char *array1 = "ATGGT";
	char *array2 = "ATGCC";
	int length = (int) strlen(array1);	
	int dist = strcmp (const char *array1, const char *array2);

	printf("A program to score Hamming distance: \n");
	printf("%d",dist);

		

	exit(0);
}//main

