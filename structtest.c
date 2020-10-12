/*

 How can structs be declared and used... aren't they like C++ classes, but 
 without the methods?
 
 */

#include <stdio.h>
#include <string.h>

// 50 characters per car maker and model should be enough... right?
#define MAKER_CHARLIM 50

struct Car {
    int capacity; // how many people can ride
    char maker[MAKER_CHARLIM];
    int price; // in USD
    int passengers; // how many people are in
};

struct Car car_factory(int cap, int prc, char *mk)
{
    struct Car c;
    c.capacity = cap;
    strncpy(c.maker, mk, MAKER_CHARLIM - 1); // make space for '\0'!
    c.price = prc;
    c.passengers = 1; // only driver by default.
    printf("New %s created.\n", c.maker);
    return c;
}

void load_passengers(struct Car *c)
{
    if (c->passengers < c->capacity) {
        c->passengers += 1;
        printf("One passenger boarded %s (%d people in)\n", 
            c->maker, c->passengers);
    }
    else {
        printf("%s is full (%d people), cannot pick up passenger.\n", 
            c->maker, c->capacity);
    }
}

int main(int arg, char **argv)
{
    struct Car sports = car_factory(2, 90000, "Audi TT");
    struct Car family = car_factory(7, 33000, "Ford Explorer");

    if (family.capacity > sports.capacity) {
        printf("%s can fit a whole family in it.\n", family.maker);
    }

    printf("This %s costs a pretty penny: %d USD!\n", sports.maker, sports.price);

    for (int i = 1; i <= 10; ++i) {
        printf("Loading passenger %d...\n", i);
        load_passengers(&sports);
    }

    for (int i = 1; i <= 10; ++i) {
        printf("Loading passenger %d...\n", i);
        load_passengers(&family);
    }

    return 0;
}
