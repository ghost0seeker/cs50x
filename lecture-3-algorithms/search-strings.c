#include <stdio.h>
#include <cs50.h>
#include <string.h>

int strsum(string s);

int main(void)
{
    string strings[] = {"battleship", "boat", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");

    int search_string_length = strlen(s);

    for (int i = 0; i < 6; i++)
    {
        int array_string_length = strlen(strings[i]);
        bool char_match = true;
        if (search_string_length == array_string_length)
        {
            for (int j = 0; j < array_string_length; j++)
            {
                if (s[j] != strings[i][j])
                {
                    char_match = false;
                    break;
                }
            }

            if (char_match)
            {
                printf("Found\n");
                return 0;
            }
        }
    }

    printf("Not found\n");
    return 1;
}