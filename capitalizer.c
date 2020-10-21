/*

capitalizer.c - transform lowercase letters to uppercase as long as we're in
plain ASCII text. Any caseless characters (numbers, whitespace, punctuation...)
will be bypassed transparently.

This program should take nothing but the C standard library to compile, but
has a limitation of the length of the string that can be read. You may freely
change this in the MAX_LENGTH pragma below, or otherwise specify this in the
compiler's -D option.

Bonus: this may also be used as a simple (read: weak) substitution cipher by
simply rearranging the order of the characters. Of course, this should not be
a substitute to proper encryption!

This program is Free Software licensed under the terms and conditions of the 
GNU GPL v3. See https://gnu.org/licenses for more information.

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum length of the string (in chars) we're able to capitalize.
// You may change this according to your needs.
const size_t MAX_LENGTH = 200;

// Do not change this. Edit MAX_LENGTH instead.
// This is used so that we accommodate +1 char for NULL.
const size_t STRING_LENGTH = MAX_LENGTH + 1;


// These arrays will be used to make the equivalencies between the lower
// and upper case versions of a given chars.
// BTW: if you scramble the order, this could also be used to make a simple 
// (albeit *weak*) substitution cipher. Don't use it, though. There's no
// security in such classical cryptography
char LOWER[] = "abcdefghijklmnopqrstuvwxyz";
char UPPER[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


// This function returns the index of a given element in an char array,
// or -1 if it's not found.
// test against a string, not char array.

int indexof(char element, char* array)
{
    char *arr_ptr = array;
    int index = 0;
    while (*arr_ptr != '\0') {
        if (*arr_ptr == element) {
            // found.
            return index;
        }
        ++arr_ptr;
        ++index;
    }
    // Still here? Not found.
    return -1;
}


// Capitalize a current string into a new string.
// Make sure the strings are the same length!
void capitalize(char *cur, char *new)
{
    if (strncmp(cur, "", MAX_LENGTH) == 0)
    {
        // quit on empty string
        return;
    }

    // "trackers" of strings
    char *cur_ptr = cur;
    int counter = 0;
    
    while(*cur_ptr != '\0') {
        char target = *cur_ptr;
        int element = indexof(target, LOWER);
        if (element == -1) {
            // Already uppercase. Ignore conversion.
            new[counter] = target;
        }
        else {
            new[counter] = UPPER[element];
        }
        ++cur_ptr;
        ++counter;
    }
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Error: please pass a string to capitalize.\n");
        return 1;
    }
    char sample[STRING_LENGTH];
    char sample_new[sizeof(sample)];

    // obtain raw string from $1.
    strncpy(sample, argv[1], STRING_LENGTH);
    
    capitalize(sample, sample_new);
    
    printf("%s\n", sample_new);
    return 0;
}
