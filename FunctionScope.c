#include <stdio.h>
#include <stdlib.h>

void myFunction(char c_letter);

int main(int argc, char **argv)
{
        char c_main_letter = 'X';

        printf("In Main.  Before calling the function, c_main_letter = %c\n", c_main_letter);
        myFunction(c_main_letter);
        printf("In Main.  After calling the function, c_main_letter = %c\n", c_main_letter);

        /*
        The next line attempts to access a value outside of the scope of main
        THIS DOESN'T WORK and it's not supposed to.
        c_function_letter = 'Z';
        */

        return(0);
}/* main*/

void myFunction(char c_letter)
{
        char c_function_letter = 'Y';

        printf("In Func.  I received the letter %c\n", c_letter);
        printf("In Func.  My own letter is %c\n",c_function_letter);
        /*
        The next line attempts to access a value outside of the scope of this function
        THIS DOESN'T WORK and it's not supposed to.
        printf("Attempting to access main's own letter %c\n", c_main_letter);
        */

}
