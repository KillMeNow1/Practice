/*
        Examples of how to change terminal foreground and background colours
        E. Malins 2015-10-08
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

        int foreground_colour = 30;
        int fend = 37;
        int bend = 47;
        int background_colour = 40;


        printf("Trying out different terminal colours\n");

        while (foreground_colour <= fend)
        	{
        	for (background_colour = 40; background_colour <= bend; background_colour++)
        
        	  {
      		  printf("\x1b[0;%d;%dm Trying %d,%d",foreground_colour, background_colour, foreground_colour, background_colour);
      		  
      		  }
        	
        foreground_colour++;

         }

        return 0;

}

