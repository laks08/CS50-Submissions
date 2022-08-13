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
            int a = (int)(round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0));

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
            int green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            //red
            if(red > 255 )
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = red;
            }
            //green
            if(green>255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = green;
            }
            //blue
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

            int avgs[3] = {0,0,0};
            int n = 0;

            int a[3][3] = {{i-1, i-1, i-1}, {i, i, i}, {i+1, i+1, i+1}};
            int b[3][3] = {{j-1, j-1, j-1}, {j, j, j}, {j+1, j+1, j+1}};

            for(int x = 0; x < 3; x++)
            {
                for(int y = 0; y < 3; y++)
                {
                    if (a[x][y] >= 0 && b[x][y] >= 0)
                    {
                    avgs[0] += copy[a[x][y]][b[x][y]].rgbtRed;
                    avgs[1] += copy[a[x][y]][b[x][y]].rgbtGreen;
                    avgs[2] += copy[a[x][y]][b[x][y]].rgbtBlue;
                    n++;
                    }
                 }
             }
             avgs[0] /= n;
             avgs[1] /= n;
             avgs[2] /= n;

             image[i][j].rgbtRed = avgs[0];
             image[i][j].rgbtGreen = avgs[1];
             image[i][j].rgbtBlue = avgs[2];
        }
    }
    return;
}
