#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0;  i< height; i++)
     for (int j = 0; j < width; j++)
     {
        float blue = image[i][j].rgbtBlue;
        float green = image[i][j].rgbtGreen;
        float red = image[i][j].rgbtRed;

        {
            int average = round((red + blue + green) / 3);
            image[i]
            [j].rgbtBlue = image[i]
            [j].rgbtGreen = image[i]
            [j].rgbtRed = average;
        }

     }


    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{ for(int i = 0; i < height; i++)
  for(int j = 0; j < width;j++)
  {
    int red = image[i][j].rgbtRed;
    int blue = image[i][j].rgbtBlue;
    int green = image[i][j].rgbtGreen;


    int sepiaRed = round(0.393 * red +  0.769 * green + 0.189 * blue);
    if ( sepiaRed  > 255)
    {
        image[i][j].rgbtRed =255;
    }
    else
    {
        image[i][j].rgbtRed = sepiaRed;
    }
    int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
    if( sepiaGreen > 255)
    {
        image[i][j].rgbtGreen = 255;
    }
    else
    {
        image[i][j].rgbtGreen = sepiaGreen;
    }
    int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);
    if(sepiaBlue > 255)
    {
        image[i][j].rgbtBlue = 255;
    }
    else
    {
        image[i][j].rgbtBlue = sepiaBlue;
    }
  }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height;i++)
    for(int j = 0; j < width/2; j++)
    {
        RGBTRIPLE temp = image[i][j];

        image[i][j]= image[i][width - ( j + 1)];
        image[i][width - ( j + 1)]= temp;
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height ; i++)
    for (int j = 0 ; j < width ; j++)
    {
        int total_Red, total_Blue, total_Green;
        total_Red = total_Blue = total_Green = 0;
        float counter = 0.00;

        for (int x = -1; x < 2; x++)
        for (int y = -1 ; y < 2; y++)
        {
            int currentX = i + x;
            int currentY = j + y;
            if(currentX < 0 || currentX >(height -1)|| currentY < 0 || currentY > (width - 1))

            {
                continue;
            }

            total_Red += image[currentX][currentY].rgbtRed;
            total_Green += image[currentX][currentY].rgbtGreen;
            total_Blue += image[currentX][currentY].rgbtBlue;
            counter++;
        }
        temp[i][j].rgbtRed = round(total_Red / counter);
        temp[i][j].rgbtGreen = round(total_Green / counter);
        temp[i][j].rgbtBlue = round(total_Blue / counter);


    }
    for(int i = 0 ; i < height; i++)
    for (int j = 0; j < width; j++)
    {
        image[i][j].rgbtRed = temp[i][j].rgbtRed;
        image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
    }

    return;

}