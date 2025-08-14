#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int numbers[7];
    int n = get_int("Number: ");

    // linear search
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found %i at %i", n, i);
            return 0;
        }
    }

    printf("%i not found", n);
    return 1;
}