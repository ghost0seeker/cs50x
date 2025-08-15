#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"David", "John", "Yuliia"};
    
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750", "+1-617-495-1000"};

    string name = get_string("Name: ");

    for (int i = 0; i < 3; i++)
    {
        if(strcmp(name, names[i]) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}