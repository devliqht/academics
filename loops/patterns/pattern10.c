#include <stdio.h>

/*
        1           space = 8, i = 1
      2 1 2         space = 6, i = 2
    3 2 1 2 3 
  4 3 2 1 2 3 4
5 4 3 2 1 2 3 4 5
*/

int main(void) {
    int space = 8, n = 5, s = 1;
    for (int i = 1; i <= 5; i++) {
        int var = i;
        for(int k = 0; k < space; k++) {
            printf(" ");
        }
        for (int j = 1; j <= s; j++) {
            printf("%d ", var);
            if (j > (s/2)) {
                var++;
            } else {
                var--;
            }
        }
        s += 2;
        space -= 2;
        printf("\n");

    }
}