/*

Learn how to clear strings, while still keeping them clear and without risk
of buffer overflows.

 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char line[20]; // reading buffer

    printf("What is your name? ");
    fgets(line, sizeof(line) - 1, stdin);

    // clear the line of the trailing newline. Change it to NULL.
    for (int i = 0; i < sizeof(line); ++i) {
        if (line[i] == '\n')
            line[i] = '\0';
    }

    // use 'n' methods when dealing with strings (i.e. strncpy, strncpm)
    // so that you can perform safety bounds checking.
    if (strncmp(line, "", sizeof(line) - 1) == 0){
        printf("How rude of you not to answer!\n");
    }
    else {
        printf("Nice to meet you, %s!\n", line);
    }
    return 0;
}
