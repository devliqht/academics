#include <stdio.h>

void pyramid_for() {
    int rows = 5;
    int stars = 1, spaces = 0, starCount = 0;
    for (int j = 1; j < rows; j++) {
        stars += 2; 
    }
    for (int i = 0; i < rows; i++) {
        for (int k = spaces; k > 0; k--) {
            printf(" ");
        }
        for (int j = starCount; j < stars; j++) {
            printf("*");
        }
        spaces++;
        starCount += 2;
        printf("\n");
    }
}

void pyramid_while() {
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
}

void pyramid_dowhile() {
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
}

int main(void){
    pyramid_for();
    pyramid_while();
    pyramid_dowhile();
    return 0;
}