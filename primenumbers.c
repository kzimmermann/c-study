/*

 Discovering prime numbers "the hard way:" finding out if all integers until
 a given number are not divisors until we reach the given number.

 This is a very inefficient to do it, but tests out the brute-force nature of
 math: if it can be done, it will! (Thanks, computers!)

 I wonder if this could be useful in some kind of crypto library, to compute
 large primes or something?

 Licensed and released under the terms and conditions of the GNU GPL v3.
 See https://gnu.org/licenses for more information.

 */

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Error: please pass an integer to see if it's prime.\n");
        return 1;
    }
    int test;
    int counter = 2;

    // There's no boolean type (wtf?) so we test against 1 or 0.
    int prime = 1;
    sscanf(argv[1], "%d", &test);

    while(counter < test) {
        if (test % counter == 0) {
            printf("%d is not a prime number; it's divisible by %d.\n", test, counter);
            prime = 0;
            break;
        }
        ++counter;
    }

    if(prime == 1)
        printf("%d is a prime number.\n", test);
    
    return 0;
}
