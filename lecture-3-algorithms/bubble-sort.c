#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int array[] = {7, 2, 5, 4, 1, 6, 0 ,3, 9, 11, 14, 12, 13, 10, 15};
    int sorted_array[15];
    int swap = 0;

    for (int i = 0; i < 15; i++)
    {
        
        for (int j = i+1; j < 15; j++)
        {
            if (array[i] > array[j])
            {
                swap = array[i];
                array[i] = array[j];
                array[j] = swap;
            }
        }

        sorted_array[i] = array[i];
    }

    for (int i = 0; i < 15; i++)
    {
        printf("%i, ", sorted_array[i]);
    }
    printf("\n");
}