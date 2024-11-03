#include <stdio.h>

int main(void) {
    int rows = 5, copy = rows-1;
    int stars = 1, spaces = 0, starCount = 0;
    do {
        stars += 2;
        copy--;
    } while (copy > 0);
   
    do {
       int k = spaces, j = starCount;
        do {
            if (k > 0) { // Just changed every while loop to do while but an additional condition to this part since do-whiles are exit controlled.
                printf(" ");
            }
            k--;
        } while (k > 0);

        do {
            printf("*");
            j++;
        } while (j < stars);

        spaces++;
        starCount += 2;
        printf("\n"); 
        rows--; 
    } while (rows > 0);

    return 0;
}