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
	float Red;
	float Green;
	float Blue;
    for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			copy[i][j].rgbtRed = image[i][j].rgbtRed;
			copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
			copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 && j == 0)
			{
				Red = (float)(copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 4;

				Green = (float)(copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 4;

				Blue = (float)(copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 4;

                Red = round(Red);
				Blue = round(Blue);
				Green = round(Green);

				image[i][j].rgbtRed = Red;
				image[i][j].rgbtGreen = Green;
				image[i][j].rgbtBlue = Blue;
			}

			else if (j == 0 && i == (height - 1))
			{
				Red =(float)(copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed) / 4;

				Green = (float)(copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen) / 4;

				Blue = (float)(copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue) / 4;

                Red = round(Red);
				Green = round(Green);
				Blue = round(Blue);

				image[i][j].rgbtRed = Red;
				image[i][j].rgbtGreen = Green;
                                image[i][j].rgbtBlue = Blue;
			}

			else if (i == 0 && j == (width - 1))
			{
				Red = (float)(copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed)/ 4;

				Green = (float)(copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 4;

				Blue = (float)(copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 4;

				Red = round(Red);
				Green = round(Green);
				Blue = round(Blue);

				image[i][j].rgbtRed = Red;
				image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
			}

			else if(i == (height - 1) && j == (width - 1))
			{
				Red = (float)(copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed) / 4;

		 		Blue = (float)(copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue) / 4;

				Green = (float)(copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen) / 4;

				Red = round(Red);
				Green = round(Green);
				Blue = round(Blue);

				image[i][j].rgbtRed = Red;
				image[i][j].rgbtGreen = Green;
                image[i][j].rgbtBlue = Blue;
			}

			else if (j == 0 && (i > 0 && i < height - 1))
			{
				Red = (float)(copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6;

				Green = (float)(copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6;

				Blue = (float)(copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6;

				Red = round(Red);
				Green = round(Green);
				Blue = round(Blue);

				image[i][j].rgbtRed = Red;
				image[i][j].rgbtGreen = Green;
				image[i][j].rgbtBlue = Blue;
			}
			else if (j == (width - 1) && (i > 0 && i < height - 1))
			{
				Red = (float)(copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) / 6;

				Green = (float)(copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 6;

				Blue = (float)(copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 6;

				Red = round(Red);
				Green = round(Green);
				Blue = round(Blue);

				image[i][j].rgbtRed = Red;
                                image[i][j].rgbtGreen = Green;
				image[i][j].rgbtBlue = Blue;
			}
			else if (i == 0 && (j > 0 &&  j < width - 1))
			{
				Red = (float)(copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6;

				Green = (float)(copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6;

				Blue = (float)(copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6;

				Red = round(Red);
				Green = round(Green);
				Blue = round(Blue);

				image[i][j].rgbtRed = Red;
				image[i][j].rgbtGreen = Green;
				image[i][j].rgbtBlue = Blue;
			}
			else if  (i == height - 1 && (j > 0 && j < width - 1))
			{
				Red = (float)(copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed) / 6;

				Green = (float)(copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen) / 6;

                Blue = (float)(copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue) / 6;

				Red = round(Red);
				Green = round(Green);
				Blue = round(Blue);

				image[i][j].rgbtRed = Red;
				image[i][j].rgbtGreen = Green;
				image[i][j].rgbtBlue = Blue;
			}
			else
			{
				Red = (float)(copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 9;

                Green = (float)(copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 9;

                Blue = (float)(copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 9;

				Red = round(Red);
				Green = round(Green);
				Blue = round(Blue);

				image[i][j].rgbtRed = Red;
				image[i][j].rgbtGreen = Green;
				image[i][j].rgbtBlue = Blue;
			}

		}
	}
    return;
}