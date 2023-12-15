#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid_key(string key);
char substitute(char c, string key);

int main(int argc, string argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!valid_key(argv[1]))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string key = argv[1];
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", substitute(plaintext[i], key));
    }

    printf("\n");
}

bool valid_key(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }

    int freq[26] = {0};

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = tolower(key[i]) - 'a';
        if (freq[index] > 0)
        {
            return false;
        }

        freq[index]++;
    }
    
    return true;
}

char substitute(char c, string key)
{
    if (isalpha(c))
    {
        int index = tolower(c) - 'a';
        char replacement = key[index];

        if (isupper(c))
        {
            return toupper(replacement);
        }
        else
        {
            return tolower(replacement);
        }
    }
    return c;
}