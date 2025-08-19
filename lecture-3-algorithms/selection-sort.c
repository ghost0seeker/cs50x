#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int array[] = {2, 1, 0};
    int smallest_number = 0;
    int smallest_index = 0;

    for (int i = 0; i < 3; i++)
    {
        smallest_number = array[i];
        int smallest_index = i;
        
        for (int j = i+1; j < 3; j++)
        {
            if (smallest_number > array[j])
            {
                smallest_number = array[j];
                smallest_index = j;
            }
        }

        int temp = array[i];
        array[i] = smallest_number;
        array[smallest_index] = temp;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%i, ", array[i]);
    }
    printf("\n");
}