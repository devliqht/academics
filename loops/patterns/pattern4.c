#include <stdio.h>

/*
    1
    21
    321
    4321
    54321
*/

int main(void) {
    for (int i = 1; i <= 5; i++) {
        for (int j = i; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
    /*
        i = 1; j = 1; j >= 1: TRUE; j--; printf("1");

        i = 2; j = 2; j >= 1: TRUE; j--; printf("2");
        i = 2; j = 1; j >= 1: TRUE; j--; printf("1");

        
    */
}