/*
        Examples of how to change terminal foreground and background colours
        E. Malins 2015-10-08
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

        int foreground_colour = 32;
        int background_colour = 43;


        printf("Trying out different terminal colours\n");

        printf("\x1b[0;%d;%dm Trying %d,%d",foreground_colour, background_colour, foreground_colour, background_colour);
        printf("\x1b[0;37;40m\n");

        background_colour = 44;
        printf("\x1b[0;%d;%dm Trying %d,%d",foreground_colour, background_colour, foreground_colour, background_colour);
        printf("\x1b[0;37;40m\n");

        foreground_colour = 33;
        background_colour = 45;
        printf("\x1b[0;%d;%dm Trying %d,%d",foreground_colour, background_colour, foreground_colour, background_colour);
        printf("\x1b[0;37;40m\n");

        foreground_colour = 33;
        background_colour = 46;
        printf("\x1b[0;%d;%dm Trying %d,%d",foreground_colour, background_colour, foreground_colour, background_colour);
        printf("\x1b[0;37;40m\n");

        return 0;

}

