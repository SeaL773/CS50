#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

typedef uint8_t BYTE;

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (!check_format(header))
    {
        printf("Input is not a WAV file.\n");
        fclose(input);
        return 3;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not create %s.\n", argv[2]);
        fclose(input);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);
    BYTE block[block_size];

    // Move to the start of the last block of audio data
    fseek(input, -block_size, SEEK_END);

    // Write reversed audio to file
    // TODO #8
    while (ftell(input) >= sizeof(WAVHEADER))
    {
        fread(&block, block_size, 1, input);
        fwrite(&block, block_size, 1, output);

        // Move to the next block to read, going backwards
        fseek(input, -2 * block_size, SEEK_CUR);
    }

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    return (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E');
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    // Calculate block size as number of channels multiplied by bytes per sample
    return header.numChannels * header.bitsPerSample / 8;
}