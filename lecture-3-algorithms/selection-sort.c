#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int array[] = {7, 2, 5, 4, 1, 6, 0 ,3};
    int sorted_array[8];
    int smallest_number = 0;
    int idx = 0;

    for (int i = 0; i < 8; i++)
    {
        smallest_number = array[i];
        
        for (int j = i+1; j < 8; j++)
        {
            if (smallest_number > array[j])
            {
                smallest_number = array[j];
                idx = j;
            }
        }

        sorted_array[i] = smallest_number;
        array[idx] = array[i];
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%i, ", sorted_array[i]);
    }
    printf("\n");
}