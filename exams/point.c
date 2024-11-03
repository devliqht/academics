#include <stdio.h>
#include <string.h>

int x, y;
int identifyPoint();

int main(void) {
    int ret = identifyPoint();
    switch (ret) {
        case 0:
            printf("The point (%d, %d) is in Origin.", x, y);
            break;
        case 1:
            printf("The point (%d, %d) is in Q1.", x, y);
            break;
        case 2:
            printf("The point (%d, %d) is in Q2.", x, y);
            break;
        case 3:
            printf("The point (%d, %d) is in Q3.", x, y);
            break;
        case 4:
            printf("The point (%d, %d) is in Q4.", x, y);
            break;
        case 5:
            printf("The point (%d, %d) is in x-axis.", x, y);
            break;
        case 6:
            printf("The point (%d, %d) is in y-axis.", x, y);
            break;
    }
    
}

int identifyPoint() {
    printf("Enter x - coordinate: "); scanf("%d", &x);
    printf("Enter y - coordinate: "); scanf("%d", &y);

    /*
        0 - origin
        1 - quadrant I
        2 - quadrant II
        3 - quadrant III
        4 - quadrant IV
        5 - x-axis
        6 - y-axis
    */
    if (x > 0 && y > 0) {
        return 1;
    } else if (x < 0 && y > 0) {
        return 2;
    } else if (x < 0 && y < 0) {
        return 3;
    } else if (x > 0 && y < 0) {
        return 4;
    } else if (x == 0 && (y < 0 || y > 0)) {
        return 6;
    } else if (y == 0 && (x < 0 || x > 0)) {
        return 5;
    } else {
        return 0;
    }
 
}