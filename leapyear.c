/*
 
 Find leap years according to this definition:
 A leap year is any year divisible by 4, unless the year is divisible by 100, 
 but not 400.

 Trivia: leap years are also the years when the Summer Olympic Games happen!

 Licensed and released under the terms and conditions of the GNU GPL v3.
 See https://gnu.org/licenses for more information.

 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Pass an year (YYYY) to see if it's leap or not.\n");
        return 1;
    }

    int year = atoi(argv[1]);
    int is_leap = 1; // True is 1

    if (year % 4 != 0) {
        is_leap = 0;
    }
    else if (year % 100 != 0) {
        is_leap = 1;
    }
    else if (year % 400 != 0) {
        is_leap = 0;
    } 
    else {
        is_leap = 1;
    }

    if (is_leap == 1) {
        printf("%d is a leap year.\n", year);
    }
    else {
        printf("%d is not a leap year.\n", year);
    }
    return EXIT_SUCCESS;
}
