// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool uppercase_letter = false, lowercase_letter = false, number = false, symbol = false;

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (isupper(password[i]))
        {
            uppercase_letter = true;
        }
        else if (islower(password[i]))
        {
            lowercase_letter = true;
        }
        else if (isdigit(password[i]))
        {
            number = true;
        }
        else
        {
            symbol = true;
        }
    }

    return uppercase_letter && lowercase_letter && number && symbol;
}
