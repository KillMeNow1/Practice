#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void printArray(int **array, int nr, int nc);
void printRawData(int **array, int int_numColsY, int int_numRowsX);

int main(int argc, char **argv)
{
	FILE 	*fp_input;
	char	*charPtr_fileName = "feep.pbm";
	int	int_lineLength = 1024;
	char	charArr_aLine[int_lineLength];
	char 	*charPtr_aLine = &charArr_aLine[0];
	int  	int_xrez = 0, int_yrez = 0;
	int	int_currentValue = 0;
	int	n = 0;
	
	int	i = 0;  /* generic counter */
	int	x = 0, y = 0;  /* 2D array positions */ 
	/* pointer to the first element of our 2D array */
	int **int2Darr_graphics;
	
	fp_input  = fopen(charPtr_fileName, "r");
	printf("Opened file for reading\n");
	/* get a line of data from the file and put it in charArr_aLine */	
  	fgets(charArr_aLine, int_lineLength, fp_input); 
  	fgets(charArr_aLine, int_lineLength, fp_input); 
  	fgets(charArr_aLine, int_lineLength, fp_input); 
	printf("A line of input: %s\n",charArr_aLine);

	/* work out the x and y resolution of the image */
	sscanf(charArr_aLine, "%d %d", &int_xrez, &int_yrez); 
	printf("xrez: %d, yrez: %d\n", int_xrez, int_yrez);


	/* Allocate array of pointers for each col required */
	int2Darr_graphics = malloc(sizeof(int *) * int_xrez);

	/* Alocate memory for each column required */
	for (i = 0; i < int_xrez; i++) {
		int2Darr_graphics[i] = malloc(sizeof(int) * int_yrez);
    	}


	
	while( fgets(charArr_aLine, int_lineLength, fp_input) != NULL )
	{
		//printf("A line of input: %s\n",charArr_aLine);
		y = 0;
		while ( sscanf ( charPtr_aLine, "%d%n", &int_currentValue, &n ) == 1 ) {
			//printf("%d", int_currentValue);
			int2Darr_graphics[y][x] = int_currentValue;
			/* move the pointer up */
			charPtr_aLine += n;
			//printf("x: %d, y: %d\n", x, y);
			//printf("%d ",int2Darr_graphics[y][x]);
			/* done with this line, increment y and move to next line */
			y++;
		}
		charPtr_aLine = &charArr_aLine[0];
		//printf("\n");
		x++;	
	}
	/* Done with the file, close it */
	fclose(fp_input);

	/* print the data in the matrix */
	printRawData(int2Darr_graphics, int_yrez, int_xrez);
	return 0;
}/* main */

/****************************************************/
/* Function Definitions */
/****************************************************/

void printRawData(int **array, int int_numColsY, int int_numRowsX)
{

	int int_yCurrent, int_xCurrent;
	for(int_yCurrent = 0; int_yCurrent < int_numColsY; int_yCurrent++)
	{
		for(int_xCurrent = 0; int_xCurrent < int_numRowsX; int_xCurrent++)
		{
			printf("%d ",array[int_xCurrent][int_yCurrent]);
		}
		/* done with a whole row, take a new line */
		printf("\n");
	}
}/* void printRawData(3) */






