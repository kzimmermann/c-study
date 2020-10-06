/*

 Given a cartesian plane defined by (x,y), calculate the distance between 
 points A(a,b) and B(c,d):

        B
       /.
      / .
     /  .
    A....

 You do remember geometry, don' cha?

 Licensed and released under the terms and conditions of the GNU GPL v3
 See https://gnu.org/licenses for more information.

 */

#include <stdio.h>
#include <math.h>
#include <string.h>

// Represents a simple cartesian point of coordinates (X,Y)
struct Point {
    float x;
    float y;
};

// Calculates the hypothenuse of a right triangle:
float hypothenuse(float height, float width) 
{
    // could use pow() here, but it's so simple that meh.
    return sqrtf((height*height) + (width*width));
}

int main(int argc, char **argv)
{
    float distance;
    struct Point A, B;
    char line[15];

    printf("Enter space-separated X,Y coordinates of point A (ex: 3 4): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%f %f", &A.x, &A.y);

    printf("... now the same for point B (ex: 1 6): ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%f %f", &B.x, &B.y);

    distance = hypothenuse((A.y - B.y), (A.x - B.x));

    printf("The distance between A and B is %f\n", distance);

    return 0;
}
