/*
	An example of the do-while loop
	E. Malins 2011-10-10
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	int int_LCV = 0;
	int int_stop_condition = 3;


	printf("Starting a do-while loop:  \n");
	do
	{
		printf("i = %d\n", int_LCV);
		int_LCV++;
	}while(int_LCV <= int_stop_condition);
	printf("Done with our do-while loop\n\n");


	exit(0);
}/* main */

