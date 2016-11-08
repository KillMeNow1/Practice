
#include <stdio.h>
#include <stdlib.h>
#include <string.h>









// Function that will return the sequence upon prompting a header


int main (int argc, char **argv [])
{
	FILE *fp;
	char buffer[2048];	
		
	if (((fp = fopen("proteins.fasta", "r")) == NULL))
	{ 
	 	perror("LOL nope.");
	return 1;
	}
	
	
	
	while(!feof(fp))
	{
		if(fgets(buffer, 2048, fp))
		{
			// if (buffer[0] == '>') // only prints the header
			printf("%s", buffer);
		}
	}
	fclose(fp);
return 0;
}
