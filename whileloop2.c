/*
	An example of the while loop
	E. Malins 2011-10-10
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	int int_LCV = 0;
	int int_stop_condition = 3;


	printf("Starting a while loop:  \n");
	while(int_LCV <= int_stop_condition)
	{
		printf("i = %d\n", int_LCV);
		int_LCV++;
	}/* (int_LCV <= int_stop_condition) */
	printf("Done with our while loop\n");

	exit(0);
}/* main */

