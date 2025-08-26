#include <stdio.h>

int main(void)
{
    char *s = "STRING LITERAL";
    
    int i = 0;
    while (s[i] != '\0')
    {
        printf("%c", *(s+i));
        i++;
    }
    printf("\n");
}