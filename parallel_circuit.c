/*

 Calculates the total resistance across parallel circuits as derived by Ohm's
 law. 

 From Physics: (1/R_total) = (1/R_1) + (1/R_2) ... + (1/R_n)

 Make a general program that can take any number of inputs 
 (can be read interactively or by arguments).

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char line[15]; // line parser (for stdin, etc)
    float raw_resistance = 0.0; // this will have to be inverted at the end
    float buffer_r; // reads intermediate values.
    
    printf("This program calculates the equivalent resistance across parallel circuits.\n");

    while (1) {
        printf("Enter the resistance in Ohms, or '0' to end: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%f", &buffer_r);
        if (buffer_r == 0.0)
            break;
        else
            raw_resistance += (1.0 / buffer_r);
    }

    if (raw_resistance == 0.0) {
        return 0;
    }
    
    printf("The total resistance is: %f Ohms\n", 1.0 / raw_resistance);

    return 0;
}
