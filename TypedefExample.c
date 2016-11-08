#include <stdio.h>

struct Pair
{
	int a;
	int b;
};

typedef int integer;
typedef double number;
typedef struct Pair pair;

int main()
{
	integer i=1;
	number num=1.0;
	pair P;
	P.a=1; P.b=2;

	printf("%d %lf %d %d\n",i,num,P.a,P.b);
	return 0;
}
