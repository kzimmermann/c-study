/*

 Plays with several aspects of pointer properties in C.

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // defines true and false!


// Where in the corporate ladder do you fit?
enum position {WORKER, COORDINATOR, MANAGER, DIRECTOR, EXECUTIVE};

struct employee {
    long id;
    int age;
    int salary;
    enum position role;
    bool active;
};

// Hires a fresh line worker.
struct employee hire(long i, int a, int s)
{
    struct employee e;
    e.id = i;
    e.age = a;
    e.salary = s;
    e.role = WORKER;
    e.active = true;
    return e;
}

void fire(struct employee *e)
{
    e->active = false;
    printf("Employee #%ld has been terminated with the company.\n", e->id);
}

// A division of employees, supervised by a manager
#define DIVISION_MAX 5 
struct employee division[DIVISION_MAX];

int main(int argc, char **argv)
{
    // variables that will be used to construct the employee.
    long id;
    int age;
    int salary = 3000;

    int counter;

    // line-reading prompt
    char prompt[20];

    // pointer that will be used to edit employees
    struct employee *e_ptr;

    // load up the division!
    for (int i = 0; i < DIVISION_MAX; ++i) {
        printf("Enter new employee ID (8-digits): ");
        fgets(prompt, sizeof(prompt) - 1, stdin);
        sscanf(prompt, "%ld", &id);

        printf("Enter employee age: ");
        fgets(prompt, sizeof(prompt) - 1, stdin);
        sscanf(prompt, "%d", &age);

        division[i] = hire(id, age, salary);
        printf("***Employee #%ld has joined the company.\n\n", 
            division[i].id);
    }

    for (int i = 0; i < DIVISION_MAX; ++i) {
        printf("%d. #%ld\n", i + 1, division[i].id);
    }
    printf("Which one would you like to fire? ");
    fgets(prompt, sizeof(prompt) - 1, stdin);
    sscanf(prompt, "%d", &counter); 
    
    // fire the dude.
    e_ptr = &(division[counter - 1]);
    fire(e_ptr);

    return 0;
}
