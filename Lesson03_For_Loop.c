h/*
	An Example of the for loop
	E. Malins 2011-10-10
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	int int_LCV = 0;
	int int_stop_condition = 3;



	printf("Starting a for loop:  \n");
	for(int_LCV = 0; int_LCV < int_stop_condition; int_LCV++)
	{
		printf("int_LCV = %d\n", int_LCV);
	} /* for int_LCV < int_stop_condition */
	printf("Done with our for loop\n\n");


	exit(0);
}/* main */

