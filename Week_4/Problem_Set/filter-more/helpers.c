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
    RGBTRIPLE temp[height][width];

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int sumRedX = 0, sumGreenX = 0, sumBlueX = 0;
            int sumRedY = 0, sumGreenY = 0, sumBlueY = 0;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int newRow = row + i;
                    int newColumn = column + j;

                    if (newRow >= 0 && newRow < height && newColumn >= 0 && newColumn < width)
                    {
                        RGBTRIPLE pixel = image[newRow][newColumn];

                        sumRedX += pixel.rgbtRed * Gx[i + 1][j + 1];
                        sumGreenX += pixel.rgbtGreen * Gx[i + 1][j + 1];
                        sumBlueX += pixel.rgbtBlue * Gx[i + 1][j + 1];

                        sumRedY += pixel.rgbtRed * Gy[i + 1][j + 1];
                        sumGreenY += pixel.rgbtGreen * Gy[i + 1][j + 1];
                        sumBlueY += pixel.rgbtBlue * Gy[i + 1][j + 1];
                    }
                }
            }

            temp[row][column].rgbtRed = fmin(round(sqrt(sumRedX * sumRedX + sumRedY * sumRedY)), 255);
            temp[row][column].rgbtGreen = fmin(round(sqrt(sumGreenX * sumGreenX + sumGreenY * sumGreenY)), 255);
            temp[row][column].rgbtBlue = fmin(round(sqrt(sumBlueX * sumBlueX + sumBlueY * sumBlueY)), 255);
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column] = temp[row][column];
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            int pixelCount = 0;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int newRow = row + i;
                    int newColumn = column + j;

                    if (newRow >= 0 && newRow < height && newColumn >= 0 && newColumn < width)
                    {
                        sumRed += image[newRow][newColumn].rgbtRed;
                        sumGreen += image[newRow][newColumn].rgbtGreen;
                        sumBlue += image[newRow][newColumn].rgbtBlue;
                        pixelCount++;
                    }
                }
            }

            temp[row][column].rgbtRed = round((float) sumRed / pixelCount);
            temp[row][column].rgbtGreen = round((float) sumGreen / pixelCount);
            temp[row][column].rgbtBlue = round((float) sumBlue / pixelCount);
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column] = temp[row][column];
        }
    }
    return;
}
