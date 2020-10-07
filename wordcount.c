/*

 This program counts the number of words in a string (char array).

 I'm defining a "word" to be any collection of alphanumeric characters
 terminated by a whitespace character, like " ".

 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// counts the incidence of words in a string.
int count_words(char* string)
{
    // short-circuit in case of empty string.
    if (strcmp(string, "") == 0) {
        return 0;
    }

    int count = 1;
    
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ') {
            if (string[i+1] == '\0') {
                break;
            }
            else if (string[i+1] != ' ') {
                ++count;
            }
        }
    }

    return count; 
}

int main(int argc, char **argv) 
{
    if (argc == 1) {
        printf("Error: pass a string in quotes to count words!\n");
        return 1;
    }

    printf("There are %d words.\n", count_words(argv[1]));
    return 0;
}
