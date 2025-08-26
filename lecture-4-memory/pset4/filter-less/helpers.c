#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            average = round((image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed)/3.0);
            image[h][w].rgbtBlue = average;
            image[h][w].rgbtGreen = average;
            image[h][w].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int sepiaRed = round(0.393 * image[h][w].rgbtRed + 0.769 * image[h][w].rgbtGreen + 0.169 * image[h][w].rgbtBlue);
            int sepiaGreen = round(0.349 * image[h][w].rgbtRed + 0.686 * image[h][w].rgbtGreen + 0.168 * image[h][w].rgbtBlue);
            int sepiaBlue = round(0.272 * image[h][w].rgbtRed + 0.534 * image[h][w].rgbtGreen + 0.131 * image[h][w].rgbtBlue);

            if (sepiaRed > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = sepiaGreen;
            }

            if (sepiaBlue > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            int tempBlue = image[h][w].rgbtBlue;
            int tempGreen = image[h][w].rgbtGreen;
            int tempRed = image[h][w].rgbtRed;

            image[h][w].rgbtBlue = image[h][width - w].rgbtBlue;
            image[h][width - w].rgbtBlue = tempBlue;
            image[h][w].rgbtGreen = image[h][width - w].rgbtGreen;
            image[h][width - w].rgbtGreen = tempGreen;
            image[h][w].rgbtRed = image[h][width - w].rgbtRed;
            image[h][width - w].rgbtRed = tempRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int h = 0 ; h < height; h++)
    {
        for (int w = 0 ; w < width; w++)
        {
            copy[h][w] = image[h][w];
        }
    }

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int blurBlue = 0;
            int blurGreen = 0;
            int blurRed = 0;
            int pixel_count = 0;

            for (int i = -1; i < 2; i++)
            {
                if ((h+i) >= 0 && (h+i) < height)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        if ((w+j) >= 0 && (w+j) < width)
                        {
                            blurBlue += copy[h+i][w+j].rgbtBlue;
                            blurGreen += copy[h+i][w+j].rgbtGreen;
                            blurRed += copy[h+i][w+j].rgbtRed;
                            pixel_count += 1;
                        }
                    }
                }
            }

            image[h][w].rgbtBlue = round(blurBlue / (float) pixel_count);
            image[h][w].rgbtGreen = round(blurGreen / (float) pixel_count);
            image[h][w].rgbtRed = round(blurRed / (float) pixel_count);
        }
    }
    return;
}
