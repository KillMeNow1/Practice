#include <stdio.h>

int main()
{
  /* Define some variables */
  char char_a = '1';
  int int_b = 65;
  long long_c = 90;
  float float_d = 0.1;
  double double_e = 0.1;
  
  char * str_f = "abcdefg";
  
  
  /**************************************************************************
   * Printing values of variables using printf                              *
   *                                                                        *
   * Google the "printf" function for a reference of the formatting syntax! *
   **************************************************************************/
  
  printf("Printing a character\n");
  printf("char_a (as a char) = %c\n", char_a);
  printf("char_a (as an int) = %d\n", char_a);
  printf("\n");
  
  printf("Printing integers\n");
  printf("int_b (as an int)  = %d\n", int_b);
  printf("int_b (as a char)  = %c\n", int_b);
  printf("long_c (as a long) = %ld\n", long_c);
  printf("\n");
  
  printf("Printing floating point numbers\n");
  printf("float_d  (default)                 = %f\n", float_d);
  printf("float_d  (16 digits after the dot) = %.16f\n", float_d);
  printf("double_e (default)                 = %f\n", double_e);
  printf("double_e (32 digits after the dot) = %.32f\n", double_e);
  printf("\n");
  
  printf("Printing strings\n");
  printf("str_f    = %s\n", str_f);
  printf("\n");
  
  return 0;
}
