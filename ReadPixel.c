#include<stdio.h>
#include<stdlib.h>

/* Definition of the Pixel Data Type */
typedef struct pixel 
{
int red;
int blue;
int green;
} pixel;

int main(int argc,char * argv[])
{
	pixel P1;

	scanf("%d %d %d",&P1.red,&P1.blue,&P1.green);

	printf("This is how you access a member in a struct: %d.\n",P1.blue);

	return 0;
}
