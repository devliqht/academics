#include <stdio.h>

int main(void) {
    int rows = 5, copy = rows-1;
    int stars = 1, spaces = 0, starCount = 0;
    while (copy > 0) { // this gets the amount of stars similar sa katong for loop but with while
        stars += 2;
        copy--;
    }
    while (rows > 0) {
        int k = spaces, j = starCount;
        while (k > 0) {
            printf(" ");
            k--;
        }
        while (j < stars) {
            printf("*");
            j++;
        }

        spaces++;
        starCount += 2;
        printf("\n"); 
        rows--; 
    }

    return 0;
}