#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ATOM
{
	int atom_number;
	char atom_symbol[3]; /* Don't forget the '\0' at the end! */
	char atom_name[5];   
	double x;
	double y;
	double z;
	double occupancy;
	double tempfactor;
	double charge;       /* Reading the charge might be tricky. 
													Try using an if statement and checking whether the character is + or - */
}atom;

typedef struct RESIDUE
{
	int residue_number;
	char residue_name[4]; /* Again, don't forget the '\0' at the end */
	atom atoms[100];      /* No residues will ever have more than 100 atoms. However, this uses up memory...  */
									      /* Allocating this dynamically would make our program much more memory efficient.   */
												/* This won't be a problem for now, but a protein with 5000 residues could cause    */
												/* memory issues.																																		*/
}residue;

typedef struct CHAIN
{
	char chain_identifier[2];
	residue residues[1000]; /* Most protein have less than 1000 residues. So this uses up unecessary memory.    */
  									      /* Allocating this dynamically would make our program much more memory efficient.   */
	  											/* This won't be a problem for now, but a protein with 5000 residues would cause    */
		  										/* a segmentation fault.																														*/
}chain;

int main(int argc, char *argv[])
{
		/* Write your program to read a pdf file here!!! */

	return 0;
}
