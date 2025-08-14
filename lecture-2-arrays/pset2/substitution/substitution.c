#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int substitution_cipher(string key);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("ERR: No Key Provided\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("ERR: Key is not of 26 characters.\n");
        return 1;
    }

    string key = argv[1];
    int sum = 0;

    for (int i = 0, l = strlen(key); i < l; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("ERR: Key contains non alphabetical characters.\n");
            return 1;
        }

        key[i] = toupper(key[i]);
        sum += key[i];
    }

    if (sum != 2015)
    {
        printf("ERR: Key doesn't have each alphabhet exactly once.\n");
        return 1;
    }

    if (substitution_cipher(key) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int substitution_cipher(string key)
{
    string plaintext = get_string("plaintext: ");
    char cipher[strlen(plaintext)];

    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
        if (islower(plaintext[i]))
        {
            plaintext[i] = toupper(plaintext[i]);
            int m = plaintext[i] - 65;
            char cipher_char = tolower(key[m]);
            cipher[i] = cipher_char;
        }
        else
        {
            int m = plaintext[i] - 65;
            char cipher_char = key[m];
            cipher[i] = cipher_char;
        }

    }

    printf("Encrypted Message: %s\n", cipher);
    return 0;
}
