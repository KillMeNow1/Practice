#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE *fp_input;
int int_lineLength =1024;
char *file_inverted = "inv.pbm";
char char_array[int_lineLength];
int int_xrez = 0, int_yrez = 0;

fp_input = fopen("feep.pbm", "r");
fgets(char_array, int_lineLength, fp_input);
fgets(char_array, int_lineLength, fp_input);
fgets(char_array, int_lineLength, fp_input);

sscanf(char_array, "%d %d", &int_xrez, &int_yrez);
printf("xrez: %d, yrez: %d\n", int_xrez, int_yrez);
