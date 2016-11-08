#include <stdio.h>

/* 
   Last edited 2013-10-10 EJM
   Small program to demonstrate taking arguments in from
   the command line 
*/

 /* 
    Run this program like:
	./Lesson05_Command_Line_Args Badgers 123 "wrong trousers" aardvark
*/
   
int main(int argc, char *argv[])
{
    int  i;
	/* show how many arguments the program is aware of */
    printf ("argc\t= %d\n", argc);
    
	printf ("-----------\n");
    
	/* list all the arguments */
	for (i = 0; i < argc; i++)
        printf ("argv[%i]\t= %s\n", i, argv[i]);
    return 0;
}
