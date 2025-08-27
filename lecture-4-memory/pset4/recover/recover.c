#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    uint8_t block[BLOCK_SIZE];
    int idx = 0;
    char filename[9];

    FILE *card = fopen(argv[1], "rb");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    sprintf(filename, "000.jpeg");
    FILE *output = fopen(filename, "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
    }

    bool is_writing = false;

    while (fread(block, 1, 512, card) == 512)
    {
        if (block[0] == 255 && block[1] == 216 && block[2] == 255 && block[3] <= 239 && block[3] >= 224)
        {
            if (idx == 0)
            {
                fwrite(block, 1, 512, output);
                is_writing = true;
                idx++;
            }
            else
            {
                fclose(output);
                sprintf(filename, "%03i.jpeg", idx);
                output = fopen(filename, "wb");
                if (output == NULL)
                {
                    printf("Could not open file.\n");
                    return 1;
                }
                fwrite(block, 1, 512, output);
                idx++;
                is_writing = true;

            }
        }
        else
        {
            if (is_writing)
            {
                fwrite(block, 1, 512, output);
            }
        }
    }

    fclose(output);
    fclose(card);
}
