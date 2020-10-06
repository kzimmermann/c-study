/*
 
 Test many assertions to get yourself familiarized

 */

#include <stdio.h>
#include <assert.h>

// Uncomment below to allow asserting:
#define ASSERT

const int drinking_age = 18;

int main(int argc, char **argv)
{
    int age;
    char line[4];
    printf("Welcome to the bar. How old are you? ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%i", &age);

    #ifdef ASSERT
    assert(age >= drinking_age);
    #endif

    printf("Good, now come over and have a drink.\n");
    return 0;
}
