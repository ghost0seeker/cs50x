#include <stdio.h>
#include <cs50.h>

int main(void) {
    long dollars = 1;

    while (true) 
    {
        char c = get_char("Here's $%li. Double it and give it to the next person? ", dollars);
        if ( c == 'y') 
        {
            dollars *= 2;
        }
        else {
            break;
        }
    }

    printf("Here's $%li.\n", dollars);
}