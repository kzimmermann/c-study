/*

 stringsplit.c - split strings by a given character.

 Could be used as a basis for a csv parser (?)

 This program is free software released under the terms and conditions of the
 GNU GPL v3. See https://gnu.org/licenses for more information

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t MAX_LENGTH = 100;

// convenient way to pass data as a single object.
struct stringpair {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
};

// the splitter function. 
// Pass a string to be delimited, optionally a delimiter (default = ',')
// Returns a pair of strings.
struct stringpair split(char *string, char delim)
{
    struct stringpair sp;

    // start analysis at beginning of string.
    char *s_ptr = string;
    int counter = 0;

    // did we reach EOF without splitting?
    int is_eof = 1;
    while (*s_ptr != '\0') {
        if (*s_ptr != delim) {
            // copy string chars "as-is".
            sp.str1[counter] = *s_ptr;
        }
        else {
            // found the delimiter. stop copying first string
            sp.str1[counter] = '\0';
            is_eof = 0;
            break;
        }
        ++s_ptr;
        ++counter;
    }
    if(is_eof) {
        // if no delimiter was found, str1 is the full string, and 
        // str2 has to be delivered empty.
        sp.str1[counter] = '\0';
        sp.str2[0] = '\0';
    }

    // same now for str2, except we don't have to care about a delim now.
    if (!is_eof) {    
        counter = 0;
        while (*s_ptr != '\0') {
            if (*s_ptr == delim) {
                // ignore the delimiter character in the
                // final format.
                ++s_ptr;
                continue;
            }
            sp.str2[counter] = *s_ptr;
            ++s_ptr;
            ++counter;
        }
        // terminate this string so we can keep using it properly.
        sp.str2[counter] = '\0';
    }

    return sp;
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Error: please supply a string delimited by ','\n");
        return 1;
    }
    
    // default is ',' but accept alternatives.
    char delim = ',';
    if (argc == 3) {
        sscanf(argv[2],"%c", &delim);
    }

    char query[MAX_LENGTH];

    strncpy(query, argv[1], MAX_LENGTH - 1);

    struct stringpair sp = split(query, delim);
    printf("%s\n", sp.str1);
    printf("%s\n", sp.str2);
    
    return 0;
}
