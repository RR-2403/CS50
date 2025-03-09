#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>  // Include stdbool.h
#include <cs50.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[512];
    bool found_jpeg = false;
    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Check if we found a new JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file if open
            if (img != NULL)
            {
                fclose(img);
            }

            // Create a new JPEG file
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file.\n");
                fclose(card);
                return 1;
            }

            counter++;
        }

        // Write to the current JPEG file (if one is open)
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Close any remaining open files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);

    return 0;
}
