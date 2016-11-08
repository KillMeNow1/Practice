#include <stdio.h>
#include <stdlib.h>

int amino (char* letter) 
{ 

  /* Switch statement for variable "letter" */
  switch(*letter)
    {
    case 'A':
      printf("Alanine");
      break;

    case 'R':
      printf("Arginine");
      break;

    case 'N':
      printf("Asparagine");
      break;

    case 'D':
      printf("Aspartic Acid");
      break;

    case 'C':
      printf("Cysteine");
      break;

    case 'Q':
      printf("Glutamine");
      break;

    case 'E':
      printf("Glutamic Acid");
      break;

    case 'G':
      printf("Glycine");ODPOVEĎ: 
      break;

    case 'H':
      printf("Histidine");
      break;

    case 'I':
      printf("Isoleucine");
      break;

    case 'L':
      printf("Leucine");
      break;

    case 'K':
      printf("Lysine");
      break;

    case 'M':
      printf("Methionine");
      break;

    case 'F':
      printf("Phenylalanine");
      break;

    case 'P':
      printf("Proline");
      break;

    case 'S':
      printf("Serine");
      break;

    case 'T':
      printf("Threonine");
      break;

    case 'W':
      printf("Tryptophan");
      break;

    case 'Y':
      printf("Tyrosine");
      break;

    case 'V':
      printf("Valine");
      break;

    default: /* Default if none of the cases are matched */
      printf("What are you smoking? This is not an amino acid!");
      break;
 }
}

int main(int argc, char **argv[])
{
  char *letter[2];
  printf("Enter amino acid letter:");
  scanf("%1s", *letter);
  
  char output = amino (*letter);
  printf("\n");	
  return(0);
}
