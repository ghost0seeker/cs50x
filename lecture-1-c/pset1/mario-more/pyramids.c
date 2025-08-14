#include <stdio.h>
#include <cs50.h>

int get_positive_int(void);
void rhs_pyramid(int height);
void lhs_pyramid(int height);
void pyramid(int height);


int main(void)
{
    int height = get_positive_int();
    pyramid(height);
    
}

int get_positive_int(void)
{
    int height;

    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}

void rhs_pyramid(int height)
{
    int column = 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("#");
        }
        printf("\n");
        column++;
    }
}

void lhs_pyramid(int height)
{
    int column = 1;
    int whitespace = height - 1;

    for (int i = 0; i < height; i++)
    {
        for (int w = 0; w < whitespace; w++)
        {
            printf(" ");
        }
        for (int j = 0; j < column; j++)
        {
            printf("#");
        }
        printf("\n");
        whitespace--;
        column++;
    }
}

void pyramid(int height)
{
    int column = 1;
    int whitespace = height - 1;

    for (int i = 0; i < height; i++)
    {
        for (int w = 0; w < whitespace; w++)
        {
            printf(" ");
        }
        for (int j = 0; j < column; j++)
        {
            printf("#");
        }
        printf("  ");

        for (int k = 0; k < column; k++)
        {
            printf("#");
        }

        printf("\n");
        whitespace--;
        column++;
    }
}