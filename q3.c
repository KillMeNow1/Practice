
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function that will return the sequence upon prompting a header


int main (int argc, char *argv [])
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
			if (buffer[0] == '>')
			{	
				int i = 0;
				for (i = 0; i < strlen(argv[1]); i++){
					printf("argv[1][i] = %c\n" ,argv[1][i]);
				}
				
				for (i = 0; i < strlen(buffer+1); i++){
					printf("(buffer+1)[i] = %c\n" , (buffer+1)[i]);
				}
				
				//printf("%s\n%s\n",argv[1], buffer+1);
				//printf("%d %d",strlen(argv[1]), strlen(buffer+1));
				if (strcmp(argv[1], buffer+1) == 0)
				{
					fgets(buffer, 2048, fp);
					/*if (buffer[0]== '>')
					{
						printf("End of your sequence.\n");
						return 0;
					}
					else*/
						printf("%s\n", buffer);
				}
			}
					
		}
	}
	
return 0;
}
