/*

More I/O with files (reading a file until the end).

This example takes in a file with lines that go like this:

key value

where key is a string, value is an integer, used to set four variables:
 - volume
 - sensitivity
 - sizelimit
 - threads

Should skip comments; defined as lines that start with '#'

sscanf and fgets should be enough

This program is Free Software, licensed under the terms and conditions of  the
GNU GPL v3. See https://gnu.org/licenses for more information.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

// the configuration file we'd like to read:
const char filename[] = "configrc";

// This parser function takes a file and attempts to parse it for a key.
// Returns and integer value (the value), where a return of -1 means key not
// found in file.
int parse(FILE *file, char *key)
{
    int value = -1;
    int found = 0; // set to 1 if found.
    char line[255]; // buffer to read line
    char test[20]; // used to assign the value read for comparison

    while(fgets(line, sizeof(line) - 1, file) != NULL) {
        // skip comments.
        if (line[0] == '#')
            continue;

        sscanf(line, "%s %d", test, &value);

        // remember, we can't compare strings only with '=='
        if (strncmp(key, test, 20) == 0) {
            // stop on first match.
            found = 1;
            break;
        }
    }
    if (found) {
        return value;
    }
    else {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    FILE *config;
    config = fopen(filename, "r");
    if (config == NULL) {
        printf("Error: could not read %s\n", filename);
        return 1;
    }

    int volume = 1;
    int threads = 1;
    int sizelimit = 1;
    int sensitivity = 1;

    volume = parse(config, "volume");
    threads = parse(config, "threads");
    sizelimit = parse(config, "sizelimit");
    sensitivity = parse(config, "sensitivity");

    if (volume == -1)
        printf("Error: property 'volume' not found.\n");
    else
        printf("Volume set to %d\n", volume);
    
    
    if (threads == -1)
        printf("Error: property 'threads' not found.\n");
    else
        printf("Threads set to %d\n", threads);

    if (sizelimit == -1)
        printf("Error: property 'sizelimit' not found.\n");
    else
        printf("Size limit set to %d\n", sizelimit);

    if (sensitivity == -1)
        printf("Error: property 'sensitivity' not found.\n");
    else
        printf("Sensitivity set to %d\n", sensitivity);
    
    fclose(config);

    return 0;
}
