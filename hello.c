// This is my first program in C
// My real attempt, at least.

#include <stdio.h>

const int age_adulthood = 18;

typedef struct {
    int age;
    char* gender;
} person;

person create_person(int a, char* g)
{
    return (person){.age = a, .gender = g};
}

int main(int argc, char **argv) {
    int age_girl;
    int age_boy;

    char line[13]; // buffer to read at most 12 characters from input

    printf("Olá, mundo!\n");

    printf("What's the boy's age? ");
    fgets(line, sizeof(line), stdin); // read and put value in var line
    sscanf(line, "%i", &age_boy); // "parses" the line for an int

    printf("What's the girl's age? ");
    fgets(line, sizeof(line), stdin); 
    sscanf(line, "%i", &age_girl); 

    person girl = create_person(age_girl, "female");
    person boy = create_person(age_boy, "male");

    printf("Boy age: %i\n", boy.age);
    printf("Girl age: %i\n", girl.age);

    if (boy.age == girl.age) {
        printf("They are the same age.\n");
    }
    else if (girl.age < boy.age) {
        printf("The boy is older than the girl.\n");
    } 
    else {
        printf("The girl is older than the boy.\n");
    }

    if (age_girl >= age_adulthood) {
        printf("The girl is an adult.\n");
    }
    else {
        printf("The girl is a minor.\n");
    }

    if (age_boy >= age_adulthood) {
        printf("The boy is an adult.\n");
    }
    else {
        printf("The boy is a minor.\n");
    }

    if (age_boy >= age_adulthood && age_girl >= age_adulthood) {
        printf("They both could go to a bar and grab a drink.\n");
    }

    return 0;
}
