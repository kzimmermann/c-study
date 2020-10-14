/*

 Finds the mean in an array of ints using pointers.

 Of course, there are better ways to do it, but this is good to practice.

 */

#include <stdio.h>
#include <string.h>

const size_t ARR_SIZE = 10;

int main(int argc, char **argv)
{
    // Array and manipulator variables.
    int array[ARR_SIZE];
    int *array_ptr;

    // reading boilerplate.
    int temp;
    char prompt[20];
    float result;

    for (int i = 0; i < ARR_SIZE; ++i) {
        printf("Enter an integer, or 0 to quit: ");
        fgets(prompt, sizeof(prompt) - 1, stdin);
        sscanf(prompt, "%d", &temp);

        array[i] = temp;
        if (temp == 0) {
            break;
        }
    }

    // now temp will hold the temporary sum.
    temp = 0;


    for (array_ptr = array; (*array_ptr) != '\0'; ++array_ptr) { 
        temp += *array_ptr;
    }

    if (temp != 0) {
        result = (float)temp / ARR_SIZE;
    }

    printf("The average is %f\n", result);
    
    return 0;
}
