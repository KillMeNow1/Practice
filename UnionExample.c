#include <stdio.h>

union Data_type
{
	char c;
  int i;
  float f;
}; 

int main()
{
		union Data_type	union_data;

    union_data.c = '1';
    printf("union data:\nc: %c\ni: %d\nf: %.3f\n", union_data.c, union_data.i, union_data.f );

	  union_data.i = 1;
    printf("union data:\nc: %c\ni: %d\nf: %.3f\n", union_data.c, union_data.i, union_data.f );

	  union_data.f = 1.0;
    printf("union data:\nc: %c\ni: %d\nf: %.3f\n", union_data.c, union_data.i, union_data.f );

    return 0;
}
