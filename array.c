#include <stdio.h>
#include <stdlib.h>

int array (int input[])
{
	float mean;
	int sum = 0;
	int i;
	int len=(int)sizeof(input)/(int)sizeof(int);

	for (i=0; i<len; i++)
	{
		sum = input[i] + sum;
		printf("%d %d \n", len, sum);
	}
	mean=((float)sum)/len;
	printf("The mean is %f.\n", mean);
}


int main (int argc, char **argv)
{
int x;
int inputs[4]={1,2,3,4};
printf("%d\n", (int)sizeof(inputs)/(int)sizeof(int));
//printf("%d\n", argc);
//for (x=0; x<argc; x++)
//{

//	inputs[x] = atoi(argv[x+1]);
//}
array(inputs);
return(0);
}
