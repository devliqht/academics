#include <stdio.h>

/*
    1 space = 4, i = 1, j = 1, j <= 1
   12 space = 3, i = 2, j = 1, j <= 2
  123
 1234
12345
*/
int main(void) {
    int space = 4;
    for (int i = 1; i <= 5; i++) {
        for (int k = 0; k < space; k++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        space--;
        printf("\n");
    }
}