/*

vsh - V-Shell: an interactive shell that can 'cat' files and write to them,
implemented in pure standard C, as an exercise in file IO.

Who knows, I might expand this to make it into a real vsh in the future!

This program is Free Software, licensed under the terms and conditions of the
GNU GPL v3. See https://gnu.org/licenses for more information.

 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PROGNAME vsh

void helper()
{
    printf("vsh - an interactive shell to read and write files.\n");
    printf("Commands are cat <filename> or write <filename>\n");
}

int main(int argc, char **argv)
{
    helper();
    return 0;
}
