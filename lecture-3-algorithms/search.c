#include <stdio.h>
#include <cs50.h>
#include <string.h>

int strsum(string s);

int main(void)
{
    string strings[] = {"battleship", "boat", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");

    int search_string_Sum = strsum(s);

    for (int i = 0; i < 6; i++)
    {
        int array_string_sum = strsum(strings[i]);
        if (array_string_sum == search_string_Sum)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

int strsum(string s)
{
    int ss = 0;

    for (int i = 0, l = strlen(s); i < l; i++)
    {
        ss += s[i];
    }

    return ss;
}