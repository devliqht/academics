#include <stdio.h>

/*
    54321 
    4321
    321
    21
    1
*/
int main(void) {
    for (int i = 5; i > 0; i--) {
        for (int j = i; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}