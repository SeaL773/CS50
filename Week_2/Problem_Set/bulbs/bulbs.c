#include "cs50.h"
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

/* int main(void)
{
    string text = get_string("Text: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int ascii_value = text[i];
        int base_2[BITS_IN_BYTE];

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            base_2[j] = 0;
        }

        int k = BITS_IN_BYTE - 1;
        while (ascii_value > 0)
        {
            base_2[k] = ascii_value % 2;
            ascii_value /= 2;
            k--;
        }

        for (int l = 0; l < BITS_IN_BYTE; l++)
        {
            print_bulb(base_2[l]);
        }
        printf("\n");
    }
} */

// Much simplicity and efficiency
int main(void)
{
    string text = get_string("Text: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int ascii_value = text[i];

        // Loop through each bit in the character
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            // Extract each bit of the character
            // (ascii_value >> j) shifts the bits of ascii_value to the right by j positions
            // & 1 performs a bitwise AND with 1, isolating the rightmost bit
            int bit = (ascii_value >> j) & 1;
            print_bulb(bit);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
