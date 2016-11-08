/*==============================================================================
/
/       Filename:  c_Solution.c
/    Description:  C solution for File IO practical
/        Version:  1.0
/        Created:  06/10/14 18:39:34
/        Revised:  31/10/16
/         Author:  J. Leem (), leem@stats.ox.ac.uk
/         Edited:  C. Regep (), cristian.regep@dtc.ox.ac.uk
/        Company:  University of Oxford
/
/==============================================================================*/

#include<stdio.h>           /* Functions related to File IO */
#include<stdlib.h>          /* Used for memory allocation */
#include<string.h>          /* String-related functions. */

#define MAXLENGTH 2048      /* For the purposes of this practical, we have set a limit of a
                               protein sequence having 2048 amino acids as the max length */

#define LINELIMIT 80        /* It is recommended that a FASTA file has <=80 characters per line.
                               Hence we define a constant value, named LINELIMIT, which indicates
                               how many characters we tolerate for a line in a FASTA file. */

#define ALPHABET 26         /* This constant holds the number of letters in an alphabet; this is
                               useful when we plot histograms later and count for the instance of
                               specific characters in a FASTA file. */

void viewFile(char *filename);
void listHeaders(char *filename);
void getSequence(char *filename, char *proteinID);
void saveToFile(char *input, char *output, char *proteinID);
void fileReader(char *input, long fileSize, char *fileStore);
long determineSize(char *input);

void histoWrapper(char *filename);
void histogram(char *sequence, int *charCount);
void printHistogram(int *charCount);
void printStalactiteGram(int *charCount);
int detMax(int *charCount);

void lengthWriter(char *input, char *output);
void seqToMemory(char *input, int numSequences);

int main(int argc, char* argv[]){


  viewFile("proteins.fasta");
  listHeaders("proteins.fasta");

  /* Check to see if we have provided a command-line argument; if not, then return an error message.*/
  if(argv[1] == NULL)
  {
    perror("Provide a header name for getSequence and saveToFile! Skipping these!\n");
  }
  else
  {
    getSequence("proteins.fasta", argv[1]);
    saveToFile("proteins.fasta", "output.fasta", argv[1]);
  }

  /*
   * myFileSize is a long type of variable which holds the number of bytes in a file using
   * the determineSize function.
   */

  long myFileSize;
  myFileSize = determineSize("proteins.fasta");

  /* Initialise a char array to store output from fileReader.*/
  char *fileStore;
  fileStore = malloc(sizeof(char) * myFileSize);

  /* Pass the pointer to the char array in the function */
  fileReader("proteins.fasta", myFileSize, fileStore);

  histoWrapper("proteins.fasta");
  lengthWriter("proteins.fasta", "output.csv");
  seqToMemory("proteins.fasta", 5);
  return 0;
}

void viewFile(char *filename)
{

  /*
   * File viewer which loads all headers and sequences. (Task 1)
   */

  /*
   * Set up a file handle and a buffer to store strings; we know that there are 80 amino acid characters per line,
   * and knowing that each line has a newline character in the file ('\n'), and a string in C has a string terminator
   * character ('\0'), we should have a char array with 80 (LINELIMIT) + 1 + 1 = 82.
   */

  FILE *fp;
  char buffer[LINELIMIT+2];

  /* Open file using file handle fp */
  fp = fopen(filename, "r");

  /* While we are not at the end of file... */
  while(!feof(fp))
  {
    /*
     * If we can get data onto buffer, print it out to screen.
     * fgets takes the char array "buffer",
     * the number of characters to be read (specified by LINELIMIT+2)
     * and the file handle, fp, from which characters are read from
     */

    if(fgets(buffer, LINELIMIT+2, fp))
    {
      printf("%s", buffer);
    }

  }

  /* Close the file handle! */
  fclose(fp);
}

void listHeaders(char *filename)
{

  /*
   * Lists all the headers of the sequence; headers are indicated by the '>' character (Task 2)
   */

  FILE *fp;
  fp = fopen(filename, "r");

  /*
   * Set up an integer variable to hold the output from the fgetc function;
   * fgetc returns a byte from the file handle which is a char cast to an int
   * Hence we assign the output of fgetc into an int type variable
   */

  int character;

  while(!feof(fp))
  {
    /*
     * fgetc is a function that takes the file handle as its argument;
     * As mentioned above, it's a char cast to an int, so we assign the
     * output of fgetc to character
     */

    character = fgetc(fp);

    /* Read the file character-by-character; have we encountered a '>'? */
    if( character == '>' )
    {

      /*
       * Iterate continually until we reach a newline character.
       * We can do this by using while(1), which is a way to run
       * a set of commands within the while loop until we reach a
       * condition to break the while loop.
       */

      while(1)
      {
        /* Continue reading character-by-character */
        character = fgetc(fp);

        /*
         * As we read the file, when we reach the newline character '\n',
         * we assume that the newline indicates the end of the header, and
         * we stop the while loop. Alternatively, if we reach the end of the
         * file (EOF), stop further reading.
         */

        if(character == '\n' || character == EOF)
          break;

        /* Print to screen. */
        printf("%c", character);

      }

      /* Print a new line to screen. */
      printf("\n");

    } /* End of character == '>' loop */

  } /* End of feof while loop */

  /* Close file handle! */
  fclose(fp);

}

void getSequence(char *filename, char *proteinID)
{

  /*
   * Given a sequence header specified in proteinID, we return that protein's sequence (Task 3)
   * e.g. mySequence = getSequence("proteins.fasta", O43323.2WG3); -> sequence of O43323.2WG3
   */

  FILE *fp;
  char buffer[LINELIMIT+2];
  int character;
  fp = fopen(filename, "r");


  while(!feof(fp))
  {

    character = fgetc(fp);

    if( character == '>')
    {
      /*
       * n is used to trail along and fill in our char array (buffer) for each character of the
       * header in the FASTA file
       */

      size_t n = 0;

      /* When we reach a '>', read the header or protein name */
      while(1)
      {

        character = fgetc(fp);

        /*
         * Once we hit a newline character we can assume we read the entire header,
         * so break off the while loop. Or if we have reached the end-of-file, terminate
         */
        if(character=='\n' || character == EOF)
          break;

        /* Load a character into a char array*/
         buffer[n++] = character;
      }

      /* Terminate the char array with the null character. */
      buffer[n] = '\0';

      /* Compare the array with the given protein ID; if it's the same, then read the trailing sequence */
      if(strncmp(buffer, proteinID, LINELIMIT+2) == 0)
      {
        /* Now continue reading */
        while(1)
        {
          character = fgetc(fp);

          /* If we encounter another header, or the end of the file (EOF), stop reading it. */
          if( character == '>' || character == EOF)
            break;

          /* Print otherwise. */
          printf("%c", character);
        }
      } /* End of string comparison if statement */

    } /* End of if character == '>' */

  } /* End of feof loop */

  /* Close file handle!*/
  fclose(fp);

}

void saveToFile(char *input, char *output, char *proteinID)
{
  /*
   * Save the output from getSequence into an output file specified in output (Task 4)
   */

  /* Create two file handles*/
  FILE *fp;
  FILE *out;
  char buffer[LINELIMIT+2];
  int character;

  fp = fopen(input, "r");

  /* For writing to file, we need to set up a file handle that opens a file in write mode */
  out = fopen(output, "w");

  while(!feof(fp))
  {
    character = fgetc(fp);

    if( character == '>')
    {
      size_t n = 0;

      /* When we reach a ">", read the header or protein name */
      while(1)
      {
        character = fgetc(fp);
        if(character == '\n' || character == EOF)
          break;

        /* Load a character into a char array */
        buffer[n++] = character;
      }

      /* Terminate the char array with the null character. */
      buffer[n] = '\0';

      /*
       * Compare the buffer with the given protein ID; if it's the same, then read the trailing sequence
       * strncmp takes two strings (buffer, proteinID) and a number of characters to compare; (LINELIMIT+2)
       * A non-zero value from strncmp indicates that the two strings are not the same!
       */

      if(strncmp(buffer, proteinID, LINELIMIT+2) == 0)
      {
        /*
         * fputc writes a character into file;
         * fputc takes two arguments; the character and the file handle.
         */

        fputc('>', out);

        /* fputs is similar to fputc, except that we take a string rather than a character*/
        fputs(buffer, out);

        /* Add a new line into file for prettier formatting. */
        fputc('\n', out);

        /* Now continue reading until we reach EOF */
        while(1)
        {
          character = fgetc(fp);

          /* If we encounter another header, stop reading. */
          if( character == '>' || character == EOF)
            break;

          /* Write every character up to the '>' into the file in the out handle using fputc */
          fputc(character, out);
        }

      } /* End of string comparison between buffer and proteinID */

    } /* End of '>' search */

  } /* End of while feof loop */

  /* Close BOTH file handles!!*/
  fclose(fp);
  fclose(out);

}

void fileReader(char *input, long fileSize, char *fileBuffer)
{

  /*
   * Read sequence from one file and store its entire contents into memory as a one-dimensional char array. (Task 5)
   * See the solution for Task 8 to see how we can store sequences as multiple char arrays
   */

  FILE *fp;
  fp = fopen(input, "r");

  /* fread is a function that reads the entire file into memory;*/
  fread(fileBuffer, fileSize, 1, fp);

  /* Print buffer to screen to see that we've read it in correctly!*/
  printf("%s", fileBuffer);

  /* Close file!*/
  fclose(fp);

}

long determineSize(char *input)
{
  /*
   * Determine size of file, in bytes, for memory allocation.
   */

  FILE *fp;
  fp = fopen(input, "r");

  /*
   * Interpret the size of file;
   * SEEK_END is used to track toward x characters away from the end of the file.
   */
  fseek(fp, 0, SEEK_END);

  /* ftell indicates the number of bytes that fp has trailed.*/
  long fp_Size = ftell(fp);

  /* CLOSE THE FILE HANDLE! */
  fclose(fp);

  /* Return the size of file AFTER file closure.*/
  return(fp_Size);

}


void histoWrapper(char *filename)
{

  /*
   * Calls two functions to draw histograms for each sequence in the FASTA file. (Task 6)
   * histoWrapper calls multiple functions (and is a wrapper for these functions);
   * It calls:
   *    void histogram            (generates the data for a histogram)
   *    void printHistogram       (prints out a horizontal histogram)
   *    void printStalactiteGram  (prints out a stalactite histogram)
   */

  FILE *fp;
  fp = fopen(filename, "r");
  int character;

  /* Initialise a int array that holds the number of characters*/
  int *charCount;

  /* Use calloc to clear out memory space;  */
  charCount = calloc(ALPHABET, sizeof(int));

  /*
   * Remember to allocate enough memory for storing a sequence;
   * A sequence is going to be, at most, 2048 amino acids long (MAXLENGTH)
   * and a header is going to be one line of a FASTA file, so we allocate
   * 82 bytes as explained earlier
   */

  char sequence[MAXLENGTH];
  char header[LINELIMIT+2];

  while(!feof(fp))
  {
    character = fgetc(fp);

    if( character == '>')
    {

      size_t n = 0;

      /* When we reach a ">", read the header or protein name */
      while(1)
      {
        character = fgetc(fp);
        if(character == '\n' || character == EOF)
          break;

        /* Load a character into a char array*/
        header[n++] = character;
      }
      /* Terminate the char array with the null character.*/
      header[n] = '\0';

      /* Print the header per sequence*/
      printf("%s\n", header);

    }

    else
    {
        /* For every line that does NOT start with '>' ...  */

        size_t n = 0;

        while(1)
        {
          character = fgetc(fp);

          /* If we encounter another header, stop reading.*/
          if( character == '>')
          {
            /*
             * Rewind back along the file to invoke the above if statement on line 437
             * to read another header. By retreating back a couple of bytes from the current
             * position (SEEK_CUR), we will reach a '>' again and trigger the condition on
             * line 437 to read and print another header.
             */

            fseek(fp, -1, SEEK_CUR);
            break;
          }

          /*
           * If we encounter a newline character, don't fit it into the char array named
           * 'sequence' for counting.
           */
          else if(character == '\n')
          {
            continue;
          }
          else if(character == EOF)
          {
            break;
          }
          else
          {
            /* Add an amino acid character into sequence char array*/
            sequence[n++] = character;
          }

        } /* End of while-1 loop */

        /* Terminate the sequence */
        sequence[n] = '\0';

        /* Use histogram function to count the numebr of times that we see a character*/
        histogram(sequence, charCount);

        /* Prints a horizontal histogram*/
        printHistogram(charCount);

        /* Prints a stalactite histogram*/
        printStalactiteGram(charCount);

    } /* End of if-else for '>' */

  } /* End of feof loop*/

  fclose(fp);
}

void histogram(char *sequence, int *charCount)
{

  /*
   * Generates a histogram for each amino acid that we see >=1 times in the char
   * array 'sequence'. charCount is a blank int array that we pass in from
   * histoWrapper.
   */

  /* c is used to iterate along sequence char array*/
  int c = 0;

  /* While we have not encountered a terminating character in sequence...*/
  while( sequence[c] != '\0')
  {
    /* Check to see that the sequence contains a letter between A-Z;*/
    if(sequence[c] >= 'A' && sequence[c] <= 'Z')
      charCount[sequence[c] - 'A']++;               /* sequence[c]-'A' corresponds to an int between 0 and 26 that counts number of times we see character 'X' */

    c++;                                            /* Increment c by 1 and continue along sequence */

  } /* End of while loop*/

}

void printHistogram(int *charCount)
{
  /*
   * Prints out a histogram given an int array which was modified
   * in the function void histogram(char *sequence, int *charCount)
   */

  int c;

  /* asteriskCounter is used in a for loop to print asterisks to screen*/
  int asteriskCounter ;

  /* Go through the count int array and print out in the format specified in PDF*/
  for( c = 0; c < 26; c++)
  {
    if(charCount[c] > 0)
    {
      /* Prints out in the format 'A'   FREQUENCY */
      printf("%c\t%d\t", c+'A', charCount[c]);

      /* Use a for loop to print out the number of asterisks corresponding to charCount*/
      for(asteriskCounter = 0; asteriskCounter < charCount[c]; asteriskCounter++)
      {
        printf("*");
      }
      /* Print out new line*/
      printf("\n");

    } /* End of charcount if statement  */

  } /* End of for loop*/
}

void printStalactiteGram(int *charCount)
{
  /*
   * Prints out a stalactite (drop-down) histogram given an int array that was modified in
   * the function void histogram(char *sequence, int *charCount).
   */

  int c;

  /*
   * Declare a static int which tells us which position in charCount has the greatest frequency
   * This is determined by the detMax function. Make a static int so we don't mess with the
   * position here and remains a constant value.
   */

  static int maxPosition;
  maxPosition = detMax(charCount);

  /* Cycle through 26 letters of the alphabet; any cases where we have more than 0, print to stdout */
  for( c = 0; c < 26; c++)
  {

    if(charCount[c] > 0)
    {
      /* Prints out letters in a horizontal line*/
      printf("%c\t", c+'A');
    }
    else
    {
      /*
       * There are some letters in charCount (e.g. the letter "B") which is actually not an amino acid, and will
       * never have a count. We could also have protein sequences that only have a limited range of amino acids,
       * meaning that some amino acids had never appeared in the sequence to begin with. For simplicity's sake,
       * we don't print any information about them. To ensure these amino acids are never printed (see section
       * below), we keep these letters' counts as -1.
       */

      charCount[c] -= 1;
    } /* End of charcount if statement  */

  } /* End of for loop*/
  printf("\n");

  /* While the letter with the maximum number of character has more than 0 (for frequency)...*/
  while(charCount[maxPosition] > 0)
  {
    /* Cycle through letters again!*/
    for( c = 0; c < 26; c++)
    {
      if(charCount[c] > 0)
      {
        /* Prints out an asterisk whenever we have a count*/
        printf("*\t");
        /* Subtract 1 from count -- this subtraction condition allows us to print things vertically!*/
        charCount[c] -= 1;
      }
      else if(charCount[c] == 0)
      {

        /* Print out a blank if it's 0*/
        printf(" \t");

      } /* End of charcount if statement  */

    } /* End of for loop*/

    printf("\n");
  }

}

int detMax(int *charCount)
{
  /* Determines index of charCount where we have the greatest frequency */

  /*
   * position is used in the for loop as an incrementor, and whereMax indicates
   * the position along the charCount array where we have the greatest value
   */

  int position;
  int whereMax = 0;

  /* Before we find the true maximum, set the maximum as the 0th position of the array */
  int currMax = charCount[0];

  /*
   * Loop through the charCount int array and determine the maximum;
   * we start from the 1st (not the 0th) position of the array and compare
   * with respect to the value stored in currMax
   */

  for(position = 1; position < 26; position++)
  {
    /*
     * If charCount of position (set by incrementor) is greater than currMax,
     * then currMax is modified
     */

    if(charCount[position] > currMax)
    {
      currMax = charCount[position];
      whereMax = position;
    }
  }

  return(whereMax);
}

void lengthWriter(char *input, char *output)
{

  /*
   * Print length of sequence into CSV file defined by output (Task 7)
   * CSV files are comma-separated value files where each entry is separated
   * by a comma. The commas essentially act as column breaks
   */

  FILE *fp;
  FILE *out;

  fp = fopen(input, "r");
  out = fopen(output, "w");

  int character;
  char buffer[MAXLENGTH];

  while(!feof(fp))
  {

    character = fgetc(fp);

    if( character == '>')
    {
      size_t n = 0;

      /* When we reach a ">", read the header or protein name*/
      while(1)
      {
        character = fgetc(fp);
        if(character == '\n' || character == EOF)
          break;

        /* Load a character into a char array*/
        buffer[n++] = character;
      }

      /* Terminate the char array with the null character.*/
      buffer[n] = '\0';

      /*
       * Write the header (stored in the char array 'buffer') into the output file
       * in the 'out' handle. CSV files are separated by a comma, so write a comma using fputc
       */
      fputs(buffer, out);
      fputc(',',out);
    }

    else
    {
        size_t n = 0;
        while(1)
        {
          character = fgetc(fp);

          /* If we encounter another header, stop reading. */
          if( character == '>')
          {
            /* Rewind back along the file to invoke the above if statement on line 713 */
            fseek(fp, -1, SEEK_CUR);
            break;
          }
          else if(character == '\n')
          {
            continue;
          }
          else if(character == EOF)
          {
            break;
          }
          else
          {
            /* Add an amino acid character into buffer char array */
            buffer[n++] = character;

          } /* End of character == '>' if statement  */

        } /* End of while-1 loop  */

        /* Terminate the sequence*/
        buffer[n] = '\0';
        fprintf(out, "%d\n", (int)strlen(buffer));
    }
  }

  /* Close BOTH file handles!  */
  fclose(fp);
  fclose(out);

}


void seqToMemory(char *input, int numSequences)
{

  /*
   * Store sequences into memory. (Task 8)
   * Unlike the function fileReader (Task 5), we don't read the entire file into one huge
   * one-dimensional char array, but into several char arrays.
   */

  FILE *fp;
  fp = fopen(input, "r");

  /* seqRead is used to count how many sequences we have read.*/
  int seqRead = 0;

  int i, character;
  size_t j = 0;

  /*
   * Use a 2-dimensional char array to store sequences; each element of the
   * 2-dimensional array points to a string; sequenceArray is a 2-dimensional
   * array where each element of sequenceArray points to an amino acid sequence,
   * and headerArray is another 2-dimensional array where each element points
   * to a header
   */

  /* Allocate memory for one of the dimensions of the 2-dimensional array using malloc */
  char **sequenceArray, **headerArray;
  sequenceArray = malloc(sizeof(char*) * numSequences);
  headerArray = malloc(sizeof(char*) * numSequences);

  /* Use calloc for the other dimension and set the allocated memory to 0 */
  for(i = 0; i < numSequences; i++)
  {
    sequenceArray[i] = calloc(MAXLENGTH, sizeof(char));
    headerArray[i] = calloc(LINELIMIT+2, sizeof(char));
  }

  /*
   * Have a while loop which is dependent on two conditions: continue reading while we are
   * not at the end of file AND we've read less than the number of sequences defined in numSequences
   */
  while(!feof(fp) && seqRead < numSequences)
  {
    character = fgetc(fp);

    if( character == '>')
    {
      size_t n = 0;
      char header[LINELIMIT+2];

      /* When we reach a ">", read the header or protein name*/
      while(1)
      {
        character = fgetc(fp);
        if(character == '\n')
          break;
        /* Load a character into a char array*/
        header[n++] = character;
      }
      /* Terminate the char array with the null character.*/
      header[n] = '\0';

      /*
       * memcpy is preferred over strcpy (another function that copies strings) because strcpy will fill in the
       * rest of the memory block with zero's if the string is shorter than the prescribed amount
       * of memory that we allocate; e.g. if we allocate 82 bytes as we do here, but the string is only 100 bytes long,
       * the remaining 28 bytes are filled with 0s!
       */

      memcpy(headerArray[j], header, LINELIMIT+2);

    }
    else
    {
        size_t n = 0;
        char sequence[MAXLENGTH];
        while(1)
        {
          character = fgetc(fp);
          /* If we encounter another header, stop reading.*/
          if( character == '>')
          {
            /* Rewind back along the file to invoke the above if statement*/
            fseek(fp, -1, SEEK_CUR);
            break;
          }
          else if(character == '\n')
          {
            continue;
          }
          else if(character == EOF)
          {
            break;
          }
          else
          {
            /* Add an amino acid character into buffer char array*/
            sequence[n++] = character;
          }
        } /* End of EOF loop*/

        /* Terminate the sequence*/
        sequence[n] = '\0';

        /* Use memcpy to copy the string held in */
        memcpy(sequenceArray[j], sequence, MAXLENGTH);

       /* j is used to index the 2-dimensional char array that we made in sequenceArray */
       j++;

       /* seqRead counts the number of sequences we have read so far.*/
       seqRead++;

    } /* End of character == '>' if-statement  */

  }/* End of feof;*/

}
