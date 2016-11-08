#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 
   Last edited 2013-10-10 EJM
   Prompt the user for input, then display it 
*/

int main(int argc, char *argv[])
{
	/* somewhere to store our input */
	char charArr25_inputValue[25];
	
	/* prompt */
	printf("What is your name? ");
	
	/* Accept input in the format of a string, at most, 24 characters long */
	scanf("%24s", charArr25_inputValue);

	printf("Hello %s.\n", charArr25_inputValue);
	printf("Goodbye %s.\n", charArr25_inputValue);

	
	/* what if the input value was a number? */
	int x = atoi(charArr25_inputValue);
	printf("n: %d\n", x+1);

	return 0;
}

