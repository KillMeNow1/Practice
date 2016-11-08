#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

/*Makes a 2D array of char which is x_size * y_size */
char** MakeArray(int x_size, int y_size)
{
  int i;
  char** new_array = malloc(y_size*sizeof(char*));
  for (i=0; i<y_size; i++) {
    new_array[i] = malloc(x_size*sizeof(char)); 
  }
  return new_array;
}

/*Frees up a 2D array of char which is x_size * y_size */
void FreeArray(char** array, int x_size, int y_size)
{
  int i;
  for (i=0; i<y_size; i++) {
    free(array[i]); 
  }
  free(array);
}

/*
 * Read header data from Netpbm .ppm binary file so that arrays can be resized.
 */
void ReadHeaderFromPpm(char* fileName, int* x_size, int* y_size)
{
  FILE* in_file;
  in_file = fopen(fileName, "r");
    
  /* Read magic number as a line */
  char* magic = NULL;
  size_t len = 0;
  getline(&magic, &len, in_file);
  assert(strcmp(magic, "P6\n") == 0);
  free(magic);

  /* Read the x_size, y_size and bits-per-pixel from the file */
  int bits_per_value;
  fscanf(in_file, "%i %i\n%i\n", x_size, y_size, &bits_per_value);
  assert(bits_per_value == 255);
  /* Note where the file pointer is.  This is important if you want to find the beginning of the data again.*/
  int location = ftell(in_file);
  printf("File pointer is at %i.\n", location);  
  fclose(in_file);
}  
/*
 * Load from Netpbm .ppm binary file into red, green, blue arrays
 * The arrays are assumed to be correctly sized
 */
void ReadDataFromPpm(char* fileName, char** red, char** green, char** blue, int x_size, int y_size)
{
  FILE* in_file;
  in_file = fopen(fileName, "r");
    
  /* Skip 3 header lines */
  char* line = NULL;
  size_t len = 0;
  int i,j;
  getline(&line, &len, in_file);
  getline(&line, &len, in_file);
  getline(&line, &len, in_file);
  assert(strcmp(line, "255\n") == 0);
  free(line);

  /* Read all the rest of the file into red, green, blue */
  unsigned char rgb[3];
  for (i = 0; i<y_size; i++)
  {
    for (j=0; j<x_size; j++)
    {
      fread(rgb, 1, 3, in_file);
      /* You should fill red, green, blue here */
      printf("RGB = (%u, %u, %u)\n", rgb[0], rgb[1], rgb[2]);
    }
  }
  fclose(in_file);
}  


/*
 * Write to Netpbm .pgm binary file from gray arrays
 */
void WriteDataToPgm(char* fileName,  char** grey, int x_size, int y_size)
{
  FILE* out_file;
  int i,j;
  out_file = fopen(fileName, "w");

  fprintf(out_file, "P5\n%i %i\n255\n", x_size, y_size);
  /* Read all the rest of the file into red, green, blue */
  for (i = 0; i<y_size; i++)
  {
    for (j=0; j<x_size; j++)
    {
      //Writing a bit at a time...  
      fwrite(&grey[i][j], 1, 1, out_file);
    }
  }
  fclose(out_file);
}
/*
 * Write to Netpbm .ppm binary file from red, green, blue arrays
 */
void WriteDataToPpm(char* fileName, char** red, char** green, char** blue, int x_size, int y_size)
{
  FILE* out_file;
  int i,j;
  out_file = fopen(fileName, "w");

  fprintf(out_file, "P6\n%i %i\n255\n", x_size, y_size);
  /* Write the rest of the file as red, green, blue... */
  
  fclose(out_file);
}

/*
 * Combine red, green and blue into an intensity
 */
void RgbToIntensity( char** red, char** green, char** blue, char** grey, int x_size, int y_size)
{
  /* Combine rgb into intensity here */
}
/*
 * Compute grad_x grad_y from the intensity
   Grad_x stencil is
   -1 0 1
   -2 0 2
   -1 0 1
   Grad_y stencil is
   -1 -2 -1
    0  0  0
    1  2  1
   Use to make grad ( Magnitude ) and direction (Inverse Tan)
 */
void ComputeGrads(  char** grey,  char** grad, char** dir, int x_size, int y_size)
{
  int i,j;
  for (i=1; i<y_size-1; i++){
    for (j=1; j<x_size-1; j++){
      int grad_x, grad_y; /*Note that grad_x, grad_y in the approximate range (-1024, 1024)*/
      grad_x = - grey[i-1][j-1] - 2*grey[i][j-1] - grey[i+1][j-1]  //j-1
               + grey[i-1][j+1] + 2*grey[i][j+1] + grey[i+1][j+1]; //j+1
      grad_y = + grey[i-1][j-1] + 2*grey[i-1][j] + grey[i-1][j+1]  //i-1
               - grey[i+1][j-1] - 2*grey[i+1][j]  - grey[i+1][j+1];//i+1
      assert(grad_x < 1024);
      assert(grad_x > -1024);
      assert(grad_y < 1024);
      assert(grad_y > -1024);
      /* When computing you might want to equalize or cap the gradient values */
    }
  }
}


int
main(int argc, char* argv[])
{
    char** red;
    char** green;
    char** blue;
    int x_size;
    int y_size;

    /*Read the headers, make the arrays and read the data into them.*/
    ReadHeaderFromPpm("cabbage.ppm", &x_size, &y_size);
    red = MakeArray(x_size, y_size);
    blue = MakeArray(x_size, y_size);
    green = MakeArray(x_size, y_size);
    ReadDataFromPpm("cabbage.ppm", red, green, blue, x_size, y_size);
    /* Used to check fidelity...    WriteDataToPpm("copy.ppm", red, green, blue, x_size, y_size); */
    
    /* Convert to greyscale intensity */
    char** grey =  MakeArray(x_size, y_size);
    RgbToIntensity(red, green, blue, grey, x_size, y_size);
    /* Used to check fidelity...     WriteDataToPgm("copy.pgm",  grey, x_size, y_size);  */

    char** grad =  MakeArray(x_size, y_size);
    char** dir =  MakeArray(x_size, y_size);
    ComputeGrads(grey, grad, dir, x_size, y_size);

    /*Free up all the arrays*/
    FreeArray(red, x_size, y_size);
    FreeArray(green, x_size, y_size);
    FreeArray(blue, x_size, y_size);
    FreeArray(grey, x_size, y_size);
    FreeArray(grad, x_size, y_size);
    FreeArray(dir, x_size, y_size);
    
    return 0;
}
