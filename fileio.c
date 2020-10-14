/*

Testing file I/O - a little better than last time...

Reading, writing, appending files, with their errors accounted for.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// line buffer size
const size_t MAX_LINESIZE = 200;

int main(int argc, char **argv) 
{
    char filename[] = "example.txt";
    FILE *temp;
    char *testwrite_ptr; // tests whether writes are successful.

    // buffer to get content
    char line[MAX_LINESIZE];

    temp = fopen(filename, "r");
    if (temp == NULL) {
        printf("Could not open file '%s' for reading.\n", filename);
        printf("Hint: have you created it?\n");
        // no need to close what we didn't open in first place! ;)
        return 1;
    }

    // read some kind of data from the file, same as stdin:
    fgets(line, sizeof(line) - 1, temp);
    
    printf("Here's what the 200 chars from the file look like:\n");
    printf("%s\n", line);

    int status = fclose(temp);
    if (status != 0) {
        printf("There was an error closing the file.\n");
        return 1;
    }

    printf("Now write something to the file (up to 200-char): ");
    fgets(line, sizeof(line), stdin);

    temp = fopen(filename, "a");
    if (temp == NULL) {
        printf("Could not open file '%s' for writing.\n", filename);
        return 1;
    }
    
    // there's implicit conversion in fputs here, but I don't quite get it
    testwrite_ptr = fputs(line, temp);
    if (testwrite_ptr == NULL) {
        printf("Could not write to file '%s'\n", filename);
    }

    status = fclose(temp);
    if (status != 0) {
        printf("There was an error closing the file.\n");
        return 1;
    }
    return 0;
}
