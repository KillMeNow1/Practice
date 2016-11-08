/* this is question 9 worksheet 3
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	int fn_1 = 1;
	int fn_2 = 0;
	int temp = 0;
	int n0 = 1;
	int n = 15;


	printf("This is the first fifteen numbers of Fibonacci sequence:  \n");
	while(n0 < n)
	{
		temp = fn_1;
		fn_1 = fn_1 + fn_2;
		fn_2 = temp;
		n0++;
		
		printf(" %d\n", fn_2);
	} 
	printf("Done with our for loop\n\n");


	exit(0);
}/* main */
