/*
 Program that will try to print out and convert the arguments received
 in series. Also try to identify the typed passed
 
 To make something useful out of it, I'll derive a simple command-line 
 calculator out of it.
 */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int first, second;
    int result;
    char operator;

    if (argc != 4) {
        printf("Usage: pass an expression like '2 + 2' to calculate.\n");
        return 1;
    }

    first = atoi(argv[1]);
    if (first == 0) {
        printf("Error: argument '%s' is not an integer.\n", argv[1]);
        return 1;
    }

    second = atoi(argv[3]);
    if (second == 0) {
        printf("Error: argument '%s' is not an integer.\n", argv[3]);
        return 1;
    }

    operator = argv[2][0];
    switch(operator) {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '/':
            printf("Warning: performing integer division.\n");
            result = first / second;
            break;
        case '*':
            result = first * second;
            break;
        default:
            printf("Error: operation not supported - '%s'\n", operator);
    }

    printf("%i\n", result);

    return 0;
}
