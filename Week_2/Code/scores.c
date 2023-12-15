#include "cs50.h"
#include <stdio.h>

int array_maximun;

// Prototype
float average(int length, int array[]);
int get_array_maximum(void);

int main(void)
{
    // Get scores
    int n = get_array_maximum();
    int scores[n];
    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", average(n, scores));
}

int get_array_maximum(void)
{
    do
    {
        array_maximun = get_int("How many number do you want in an array: ");
    }
    while (array_maximun <= 0);

    return array_maximun;
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
