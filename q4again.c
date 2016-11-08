#include <stdio.h>
#include <stdlib.h>


int power (int a, int b)
{
int i;
int anew = a;
	for (i=1; i<b; i++)
	{
	a = anew*a;
	}
printf("The result is %d.", a);
}

int main (int argc, char *argv [])
{
int a;
int b;
if (argc >= 3) 
{
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	printf("a is %d and b is %d.", a, b);
}
else
{
	printf("error");
}	
power (a, b);
printf("\n");
return (0);
}	

