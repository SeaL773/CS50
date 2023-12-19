#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int rgbt = round((image[row][column].rgbtBlue + image[row][column].rgbtGreen + image[row][column].rgbtRed) / 3.0);
            image[row][column].rgbtBlue = image[row][column].rgbtGreen = image[row][column].rgbtRed = rgbt;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int originalRed = image[row][column].rgbtRed;
            int originalGreen = image[row][column].rgbtGreen;
            int originalBlue = image[row][column].rgbtBlue;

            int sepiaRed = fmin(round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue), 255);
            int sepiaGreen = fmin(round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue), 255);
            int sepiaBlue = fmin(round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue), 255);

            image[row][column].rgbtRed = sepiaRed;
            image[row][column].rgbtGreen = sepiaGreen;
            image[row][column].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width / 2; column++)
        {
            RGBTRIPLE temp = image[row][column];
            image[row][column] = image[row][width - column - 1];
            image[row][width - column - 1] = temp;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
