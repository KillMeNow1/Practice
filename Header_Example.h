#ifndef HEADER_EXAMPLE
#define HEADER_EXAMPLE

/* The first two lines of this file ensure that the header is */
/* included only once.										  */

/* A header file can include type, union, and struct definit- */
/* tions. 													  */ 

struct Example
{
	char Word1[6];
	char Word2[6];
};

typedef struct Example example;

/* A header file can also contain function headers. Important: */
/* A header file should NOT contain function bodies!		   */

void print_hello(); /* Note the semi-colon at the end. */

#endif
