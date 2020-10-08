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

// defines if `number` is prime by brute-force.
// returns 0 if prime, the smallest divisor if not prime.
int isprime(int number)
{
    int prime = 0;
    int counter = 2;
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
    if (argc == 1) {
        printf("Error: please pass an integer to see if it's prime.\n");
        return 1;
    }

    int test, result;
    sscanf(argv[1], "%d", &test);

    result = isprime(test);

    if (result == 0) {
        printf("%d is a prime number.\n", test);
    }
    else {
        printf("%d is not a prime number. It's divisible by %d\n", test, result);
    }

    return 0;
}
