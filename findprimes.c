/*

 Can we use the functions in primenumbers.c to find large primes?

 If so, this could have cryptographic applications... if the primes we find 
 are large enough to be secure, I guess?

 Licensed and released under the terms and conditions of the GNU GPL v3.
 See https://gnu.org/licenses for more information.

 */

#include <stdio.h>
#include <string.h>

// adapted from primenumbers.c function to use longs, not ints
// returns 0 if prime, or the smallest divisor if not prime.
long isprime(long number)
{
    long prime = 0;
    long counter = 2;
    while(counter < number) {
        // oops, found a divisor!
        if (number % counter == 0) {
            prime = counter;
            break;
        }
        ++counter;
    }

    // What, still no divisor? My gosh, we found a prime!
    return prime;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: findprimes LOWER UPPER.\n");
        printf("Tries to find primes between these numbers.\n");
        return 1;
    }

    long lower, upper; // boundaries for the test
    long result; // other testing boilerplate

    sscanf(argv[1], "%ld", &lower);
    sscanf(argv[2], "%ld", &upper);

    for (long test = lower; test <= upper; ++test) {
        result = isprime(test);
        if (result == 0) {
            printf("%ld is a prime number.\n", test);
        }
    }

    return 0;
}
