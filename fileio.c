/*

Learning how to do file IO in C. Read, Write and Append.

 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // Try to open a file for reading:
    FILE * config = fopen("/home/vman/.conkyrc", "r");

    // make a 255-char buffer to read from it.
    char buffer[255];

    fscanf(config, "%s", buffer);

    printf("Read the first 255 bytes (or line) of file, to extract:\n");
    printf("%s\n", buffer);

    int status = fclose(config);
    if (status == 0) {
        printf("File closed successfully.\n");
    }
    return 0;
}
