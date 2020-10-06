/*

 A multiple-scales temperature converter, including Fahrenheit, Celsius and
 the Kelvin scale.
 
 USAGE: tempconv CONVERSION TEMPERATURE

 Where CONVERSION is either one of:
 cf - celsius to fahrenheit.
 fc - fahrenheit to celsius
 ck - celsius to kelvin
 kc - kelvin to celsius

 Authored by kzimmermann (https://github.com/kzimmermann) as part of the 
 study of the C language.

 This program is Free Software, licensed under the terms and conditions of the
 GNU GPL v3. See https://gnu.org/licences for more information.

 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Allow debugging (find value of unknown things) by uncommenting:
// #define DEBUG

void helper()
{
    printf("USAGE: tempconv CONVERSION TEMPERATURE\n");
    printf("Where CONVERSION is either one of:\n");
    printf(" cf - celsius to fahrenheit.\n");
    printf(" fc - fahrenheit to celsius\n");
    printf(" ck - celsius to kelvin\n");
    printf(" kc - kelvin to celsius\n");
    printf(" fk - fahrenheit to kelvin\n");
    printf(" kf - kelvin to fahrenheit\n");
}

// You remember your physics classes... right?

float ctof(float celsius)
{
    float fahrenheit = ((celsius * 9) / 5) + 32;
    return fahrenheit;
}

float ftoc(float fahrenheit)
{
    float celsius = 5 * ((fahrenheit - 32) / 9);
    return celsius;
}

float ctok(float celsius)
{
    return celsius + 273;
}

float ktoc(float kelvin)
{
    return kelvin - 273;
}

float ftok(float fahrenheit)
{
    return ftoc(fahrenheit) + 273;
}

float ktof(float kelvin)
{
    return ctof(kelvin - 273);
}

// end calculation functions definitions...

int main(int argc, char **argv)
{
    if (argc != 3) {
        helper();
        return 1;
    }
    
    float input;
    char operation[12]; // string that will receive value from argv[1]
    
    strcpy(operation, argv[1]);
    sscanf(argv[2], "%f", &input); // try to read from string a float.

    #ifdef DEBUG
    printf("DEBUG: the value parsed for input is: %f\n", input);
    printf("DEBUG: meanwhile, EOF equals: %d\n", EOF);
    #endif

    // If an error happened, abort the program.
    if (input == EOF) {
        printf("Error: %s is not a number!\n", argv[1]);
        return 1;
    }

    // Can we compare string to literal?
    if (strcmp(operation, "cf") == 0) {
        printf("%f\n", ctof(input));
    }
    else if (strcmp(operation, "fc") == 0) {
        printf("%f\n", ftoc(input));
    }
    else if (strcmp(operation, "kc") == 0) {
        printf("%f\n", ktoc(input));
    }
    else if (strcmp(operation, "ck") == 0) {
        printf("%f\n", ctok(input));
    }
    else if (strcmp(operation, "fk") == 0) {
        printf("%f\n", ftok(input));
    }
    else if (strcmp(operation, "kf") == 0) {
        printf("%f\n", ktof(input));
    }
    else {
        printf("Error: unknown operation.\n");
        helper();
        return 1;
    }

    return 0;
}
