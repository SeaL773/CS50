#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string text);
char rotate(char c, int n);

int main(int argc, string argv[]) 
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    int k = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], k));
    }
    printf("\n");
}

bool only_digits(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        int rotated = (c - 'A' + n) % 26;
        return 'A' + rotated;
    }

    else if (islower(c))
    {
        int rotated = (c - 'a' + n) % 26;
        return 'a' + rotated;
    }
    
    return c;
}