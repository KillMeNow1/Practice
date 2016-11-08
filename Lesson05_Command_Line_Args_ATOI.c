#include <stdio.h>
#include <stdlib.h>

/* 
   Last edited 2013-10-10 EJM
   Take an argument from the command line and convert it 
   so it can be used as an integer. 
*/
 
 /* 
    Run this program like:
	./Lesson05_Command_Line_Args_ATOI 123
*/
 
 
int main(int argc, char *argv[])
{
	int int_convertedString = 0;
 
	/* 
	   first example.. without converting ascii to integer 
	   looking to see if the input argument is < 10, == 10, or > 10
	*/
    printf ("-----------\n");

	if(argv[1] > 10)
	{
		printf ("First arg is > 10\n");
	}else if (argv[1] == 10)
	{
		printf ("First arg is equal to 10\n");
	}else
	{
		printf ("First arg is < 10\n");
	}
	
	/* convert the first input argument from a string, to an int */
	int_convertedString  = atoi(argv[1]);

	printf ("-----------\n");
	printf ("Converted value = %d\n", int_convertedString);
	printf ("-----------\n");

	
	/* looking to see if the input argument is < 10, == 10, or > 10 */	
	if(int_convertedString >= 10)
	{
		printf ("First arg is > 10\n");
	}else if (int_convertedString == 10)
	{
		printf ("First arg is equal to 10\n");
	}else
	{
		printf ("First arg is < 10\n");
	}
	

    return 0;
}
