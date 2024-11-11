#include <stdio.h>

/*
12345
 1234
  123
   12
    1
*/

int main(void) {
    for (int i = 5; i > 0; i--) {
        for (int k = 5; k > i-1; k--) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) { 
            printf("%d", j);
        }
        printf("\n");
    }
}