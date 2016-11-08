/*==============================================================================
//
//       Filename:  c_Problem.c
//    Description:  Template file for the practical in C.
//        Version:  1.0
//        Created:  31/10/2016
//         Author:  Jin Leem <leem@stats.ox.ac.uk>
//
/==============================================================================*/

#include<stdio.h>
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

void task1();
void task2();
void task3();
void task4();
void task5();
void task6(char *sequence, int *charCount);
void task7();
void task8();
void task9();

int main(int argc, char *argv[]){

    task1();
    task2();
    task3();
    task4();
    task5();

    /*
        For task6, create an integer array charCount.
        Use calloc to clear out memory space, equivalent to the length of ALPHABET.
        We use the size of int as blocks, i.e. have 26 int--sized blocks as charCount
    */
    int *charCount;
    charCount = calloc(ALPHABET, sizeof(int));

    /* Initialise a char array */
    char *string;
    string = "GMAGAIASRMSFSSLKRKQPKTFTVRIVTMDAEMEFNCEMKWKGKDLFDLVCRTLGLRETWFFGLQYTIKDTVAWLKMDK";
    task6(string, charCount);

    for(int i = 0; i < ALPHABET; i++){
        if(charCount[i] > 0)
        {
          /* Prints out in the format 'A'   FREQUENCY */
          printf("%c\t%d\n", i+'A', charCount[i]);
        }
    }

    
    task7();
    task8();
    task9();
    return(0);
}

void task1(){
    /*
        Open proteins.fasta and print the lines onto screen.
    */
}
void task2(){
    /*
        Look for headers (lines starting with '>') and print these onto screen
    */
}
void task3(){
    /*
        Using the command line, pass the name of a particular header and print.
        i.e. you should be able to run ./program O43323.2WG3
    */
}
void task4(){
    /*
        Build on from Task 3 and pass the output into a new FASTA file.
        You can either write to a new file, e.g. fputs("string", fp);
        or use the redirection flags, e.g. ./program O43323.2WG3 > output.fasta
    */
}
void task5(){
    /*
        Make a program that reads in two files from command line, i.e.
        ./program file1.fasta file2.fasta
    */
}
void task6(char *sequence, int *charCount){
    /*
        Print a histogram for each sequence of the FASTA file describing the amino acid
        frequency. The output should display the histogram as a barplot of asterisks.
        Here's a sample function to get you started.
    */

    /* Initialise an iterator, i */

    int i = 0;
    /*
        alphaDist is an integer value that will tell us how far we are from the letter 'A'.
        e.g. alphaDist == 0 for 'A', and alphaDist == 2 for 'C'.
    */
    int alphaDist;

    /* While we have not encountered a terminating character in sequence...*/
    while(sequence[i] != '\0'){

        /* Check to see that the ith character in sequence contains a letter between A-Z;*/
        if(sequence[i] >= 'A' && sequence[i] <= 'Z'){
            /* sequence[i]-'A' corresponds to an int between 0 and 26, indicating the
            distance of the letter away from A */
            alphaDist = sequence[i] - 'A';

            /* add the alphaDist--th position of charCount by 1 */
            charCount[alphaDist]++;

            /* Increment i by 1 and continue along sequence */
            i++;
        }

    } /* End of while loop */
}
void task7(){
    /*
        This is probably the hardest task, but if you've done Task 6, this is doable!
        Make the histogram from Task 6 print vertically. Hint: sort by the most frequent
        amino acids in the sequence.
    */
}
void task8(){
    /*
        Count the number of characters per sequence, and write as a CSV file. The new
        CSV file should have the header "Protein,Count". Refer to the worksheet PDF.
    */
}
void task9(){
    /*
        Read all the sequences into memory, and store it in a data structure (e.g. dictionary)
        to access sequences by header names.
    */
}
