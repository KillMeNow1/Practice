#include<stdio.h>
#include<string.h>
#include"Header_Example.h" 

int main(int argc, char *argv[])
{
	example Phrase;
	strcpy(Phrase.Word1,"Hello");
	strcpy(Phrase.Word2,"World");

	print_hello(Phrase);

	return 0;
}

/* This is where the body of your function goes. */
/* What happens if you do not include the header */
/* file by commenting line 2?					 */
void print_hello(example Phrase)
{
	printf("%s %s\n",Phrase.Word1,Phrase.Word2);
}
