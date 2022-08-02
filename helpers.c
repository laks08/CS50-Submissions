#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int a = (int)(round(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = a;
            image[i][j].rgbtGreen = a;
            image[i][j].rgbtBlue= a;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if(red>255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = red;
            }
            int green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            if(green>255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = green;
            }
            int blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if(blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = blue;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {

                    int tempr = image[i][j].rgbtRed;
                    image[i][j].rgbtRed = image[i][width - (j+1)].rgbtRed;
                    image[i][width - (j+1)].rgbtRed = tempr;

                    int tempg = image[i][j].rgbtGreen;
                    image[i][j].rgbtGreen = image[i][width - (j+1)].rgbtGreen;
                    image[i][width - (j+1)].rgbtGreen = tempg;

                    int tempb = image[i][j].rgbtBlue;
                    image[i][j].rgbtBlue = image[i][width - (j+1)].rgbtBlue;
                    image[i][width - (j+1)].rgbtBlue = tempb;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;

            if (i != 0 && i != height-1 && j != 0 && j != width-1)
            {
                image[i][j].rgbtRed = round((copy[i-1][j-1].rgbtRed + copy[i][j-1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i-1][j].rgbtRed + copy[i][j].rgbtRed + copy[i+1][j].rgbtRed + copy[i-1][j+1].rgbtRed + copy[i][j+1].rgbtRed + copy[i+1][j+1].rgbtRed)/9);
                image[i][j].rgbtGreen = round((copy[i-1][j-1].rgbtGreen + copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i][j].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i-1][j+1].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i+1][j+1].rgbtGreen)/9);
                image[i][j].rgbtBlue = round((copy[i-1][j-1].rgbtBlue + copy[i][j-1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i][j].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i-1][j+1].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i+1][j+1].rgbtBlue)/9);
            }
            else if (i == 0 && j > 0)
            {
                image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i+1][j].rgbtRed + copy[i][j+1].rgbtRed + copy[i+1][j+1].rgbtRed)/6);
                image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i+1][j+1].rgbtGreen)/6);
                image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i+1][j+1].rgbtBlue)/6);
            }
            else if (i == height-1 && j > 0)
            {
                image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i-1][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i-1][j].rgbtRed + copy[i][j+1].rgbtRed + copy[i-1][j+1].rgbtRed)/6);
                image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i-1][j+1].rgbtGreen)/6);
                image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i-1][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i-1][j+1].rgbtBlue)/6);
            }
            // else if (j == 0 && i > 0)
            // {
            //     image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i+1][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i+1][j].rgbtRed + copy[i][j+1].rgbtRed + copy[i+1][j+1].rgbtRed)/6);
            //     image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i+1][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i+1][j].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i+1][j+1].rgbtGreen)/6);
            //     image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i+1][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i+1][j].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i+1][j+1].rgbtBlue)/6);
            // }
            // else if (j == width-1 && 1 > 0)
            // {
            //     image[i][j].rgbtRed = round((copy[i][j-1].rgbtRed + copy[i-1][j-1].rgbtRed + copy[i][j].rgbtRed + copy[i-1][j].rgbtRed + copy[i][j+1].rgbtRed + copy[i-1][j+1].rgbtRed)/6);
            //     image[i][j].rgbtGreen = round((copy[i][j-1].rgbtGreen + copy[i-1][j-1].rgbtGreen + copy[i][j].rgbtGreen + copy[i-1][j].rgbtGreen + copy[i][j+1].rgbtGreen + copy[i-1][j+1].rgbtGreen)/6);
            //     image[i][j].rgbtBlue = round((copy[i][j-1].rgbtBlue + copy[i-1][j-1].rgbtBlue + copy[i][j].rgbtBlue + copy[i-1][j].rgbtBlue + copy[i][j+1].rgbtBlue + copy[i-1][j+1].rgbtBlue)/6);
            // }


        }
    }
    return;
}
