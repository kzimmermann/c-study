/*

 Prints and stores flight tickets into a specific file.

 Can print out the information for the user.

 */

#include <stdio.h>
#include <string.h>

struct time {
    int hours;
    int minutes;
};

struct flightticket {
    char fnumber[8]; // They go like: UA-2981 + \0
    char origin[4];
    char destination[4];
    struct time departure_time;
    struct time arrival_time;
};

typedef struct flightticket ticket;

ticket new_ticket(char *fn, char *or, char *dn, int ho1, int mn1, int ho2, int mn2) 
{
    ticket t;

    strncpy(t.fnumber, fn, 7);
    strncpy(t.origin, or, 3);
    strncpy(t.destination, dn, 3);
    t.departure_time.hours = ho1;
    t.departure_time.minutes = mn1;
    t.arrival_time.hours = ho2;
    t.arrival_time.minutes = mn2;

    return t;
}

int main(int argc, char **argv)
{
    // Load all the required variables...
    char fn[8];
    char or[4];
    char dn[4];
    int ho1, ho2, mn1, mn2;
    char prompt[40];

    // Read data one by one from the command-line
    printf("Flight number: ");
    fgets(prompt, sizeof(prompt) - 1, stdin);
    strncpy(fn, prompt, sizeof(fn) - 1);

    printf("Origin Airport: ");
    fgets(prompt , sizeof(prompt) - 1, stdin);
    strncpy(or, prompt, sizeof(or) - 1);

    printf("Destination Airport: ");
    fgets(prompt, sizeof(prompt) - 1, stdin);
    strncpy(dn, prompt, sizeof(dn) - 1);

    printf("Departure Time (HH:MM): ");
    fgets(prompt, sizeof(prompt) - 1, stdin);
    sscanf(prompt, "%d:%d", &ho1, &mn1);

    printf("Arrival Time (HH:MM): ");
    fgets(prompt, sizeof(prompt) - 1, stdin);
    sscanf(prompt, "%d:%d", &ho2, &mn2);

    // Create a new ticket object from data:
    ticket t = new_ticket(fn, or, dn, ho1, mn1, ho2, mn2);

    printf("Ticket created successfully. Here's the data:\n");

    printf("Flight Number: %s\n", t.fnumber);
    printf("Departure time: %d:%d\n", t.departure_time.hours, t.departure_time.minutes);

    return 0;
}
