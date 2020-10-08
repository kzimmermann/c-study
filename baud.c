/*

Calculate time taken for files transferred through a line with
a Baud rate of 960B/s. How many days did files take to 
transfer before the advent of broadband internet?

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The rate. Typed as long so as to join seamlessly along
// our calculations of seconds.
const long trate = 960;

// This function prints the appropriate time unit (ex: hour,
// day, week, month) to display as an answer based on how big
// the time frame in seconds is.
void quick_time(long seconds)
{
    if (seconds <= 60) {
        // nothing needed, as time is already in sec
    }
    else if (seconds <= 3600) {
        printf("%ld minutes", seconds / 60);
    }
    else if (seconds <= 86400) {
        printf("%ld hours", seconds / 3600);
    }
    else if (seconds <= 604800) {
        printf("%ld days", seconds / 86400);
    }
    else if (seconds <= 2592000) {
        printf("%ld weeks", seconds / 604800);
    }
    else
        printf("%ld months", seconds / 2592000);
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        printf("Error: please supply a file size in bytes.\n");
        return 1;
    }

    char line[20]; // temporary to hold argument
    long filesize;

    strcpy(line, argv[1]);
    sscanf(line, "%ld", &filesize);
    long time_taken = filesize / trate;
    
    printf("It would take %ld sec to transfer your file, or some ", time_taken);
    quick_time(time_taken);

    return 0;
}
