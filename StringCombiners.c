#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* First declare the functions. */
void stringCombiner(char *str1, char *str2, char *combined);
void stringCombiner2(char *str1, char *str2, char **pCombined);

int main()
{
  char buffer[160], *buffer2;   /* Buffer strings for the functions */
  char seq1[] = "AWSYYIGYLRLILPELQARIRTYNQHYNNLLRGAVSQRLYILLPLDCGVPDNLSMADPNIRFLDKLPQQ";
  char seq2[] = "TGDRAGIKDRVYSNSIYELLENGQRAGTCVLEYATPLQTLFAMSQYSQAGFSREDRLEQAKLFCRTLEDILADAPESQNN";


  /* VERSION 1: */
  printf("--- VERSION 1 ---\n");
  /* Check the buffer string is first empty */
  printf("initial string: %s\n", buffer);

  /* run the function */
  stringCombiner(seq1, seq2, buffer);

  /* check it worked */
  printf("final string: %s\n", buffer);
  printf("\n");


  /* VERSION 2: */
  printf("--- VERSION 2 ---\n");
  /* Cannot check initial string is empty, as it's only a pointer at
     the moment */

  /* run the function */
  stringCombiner2(seq1, seq2, &buffer2);

  /* check it worked */
  printf("final string: %s\n", buffer2);

  return(1);
}

/* function to concatenate two strings. */
void stringCombiner(char *str1, char *str2, char *combined)
{
  /* Use strcat to store the strings in the combined buffer string */
    combined = strcat(combined, str1);
    combined = strcat(combined, str2);
}


void stringCombiner2(char *str1, char *str2, char **pCombined)
{
  /* Assign memory to the pointer from main()*/
  *pCombined = (char*)malloc(160*sizeof(char));

  /* Check the memory was assigned and then do your thing */
  if (pCombined != NULL) {
    *pCombined = strcat(*pCombined, str1);
    *pCombined = strcat(*pCombined, str2);
  }

  /* Error message in case memory wasn't assigned */
  else {
    printf("ARGH, something went wrong assigning memory to pCombined!");
  }

  /* This time return the pointer as you assigned it memory */
}
