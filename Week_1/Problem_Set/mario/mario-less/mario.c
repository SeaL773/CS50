#include "cs50.h"
#include <stdio.h>

int main(void)
{
    // Prompt user input height between 1 and 8
    int tall;
    do
    {
        tall = get_int("How tall the pyramid should be: ");
    }
    while (tall < 1 || tall > 8);

    for (int row = 0; row < tall; row++)
    {
        for (int space = 0; space < tall - row - 1; space++)
        {
            printf(" ");
        }
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
