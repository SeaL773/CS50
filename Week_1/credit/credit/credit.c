#include "cs50.h"
#include <stdio.h>

int getLength(long number);
bool checkLuhn(long number, int length);
void printCardType(long number, int length);

int main(void)
{
    long card_number;
    do
    {
        card_number = get_long("Please enter the credit card number: ");
    }
    while (card_number <= 0);

    int length = getLength(card_number);

    if (checkLuhn(card_number, length))
    {
        printCardType(card_number, length);
    }
    else
    {
        printf("INVALID\n");
    }
}

int getLength(long number)
{
    int length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

bool checkLuhn(long number, int length)
{
    int sum = 0;
    bool alternate = false;

    for (int i = 0; i < length; i++)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return (sum % 10) == 0;
}

void printCardType(long number, int length)
{
    long start_digits = number;
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }

    if ((length == 15) && (start_digits == 34 || start_digits == 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 16) && (start_digits >= 51 && start_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 16 || length == 13) && (start_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
