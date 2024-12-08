#include <stdio.h>

int main(void) {
    int C[5], D[5] = { 1, 2, 3 };
    for (int i = 0; i < 5; i++) {
        printf("C[%d]: %d, D[%d]: %d\n", i, C[i], i, D[i]);
    }

    return 0;
}