/*

Plays with several aspects of pointer properties.

 */

#include <stdio.h>
#include <stdlib.h>

void square(int *input)
{
    int tmp = *input;
    *input = tmp * tmp;
}

void helper()
{
    printf("Error: provide exactly 1 integer to raise it to the square!\n");
}

int main(int argc, char **argv)
{
    // read from arguments!
    if (argc == 1) {
        helper();
        return 1;
    }
    
    // Everything taken from the arguments is interpreted as string.
    // Convert to string using the stdlib's atoi - becomes 0 if fail.
    int a = atoi(argv[1]);

    if (a == 0) {
        helper();
        return 1;
    }
    square(&a);
    printf("%i\n", a);
    return 0;
}
