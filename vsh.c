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

const size_t BUFF_SIZE = 255;

void helper()
{
    printf("vsh - an interactive shell to read and write files.\n");
    printf("Commands are cat <filename> or write <filename>\n");
}

void cat(char* filename)
{
    char line[BUFF_SIZE]; // buffer to read lines from the file.
    FILE * file;
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not read file '%s'\n", filename);
        return;
    }
    
    // Want to read all the data? Just loop around fgets: it will stop
    // once EOF is reached!
    while(fgets(line, sizeof(line), file)) {
        printf("%s",line); // no need to add line break, it already has it.
   }

    int status = fclose(file);
    if (status != 0) {
        printf("There was an error saving the file.\n");
    }
}

// write a buffer of up to 255-char to filename
void write(char *filename, char *buffer)
{
    char line[BUFF_SIZE]; // buffer used to write to the file
    int *check_ptr; // to check the status of the writing attempt.
    FILE * file; // handles file operations.

    // read as many characters as possible onto the string...
    strncpy(line, buffer, sizeof(line) - 1);

    file = fopen(filename, "a");

    if (file == NULL) {
        printf("Error: could not open file '%s' for writing.\n", filename);
        return;
    }

    // append to the file a string of max 255 char.
    check_ptr = fputs(line, file);

    if (check_ptr == NULL) {
        printf("Could not write to file '%s'\n", filename);
    }

    int status = fclose(file);
    if (status != 0) {
        printf("There was an error saving the file.\n");
    }
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Pass a filename to write a line to, and then read.\n");
        return 1;
    }

    char line[255];
    printf("Enter something to append to %s: ", argv[1]);
    fgets(line, sizeof(line) - 1, stdin);

    write(argv[1], line);
    
    printf("Now let's read the file:\n");
    cat(argv[1]);
    return 0;
}
