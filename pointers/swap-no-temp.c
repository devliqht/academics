#include <stdio.h>

void swap(int* x, int* y) {
    *x = *x - *y; // *x = 10 - 20 == -10
    *y = *x + *y; // *y = -10 + 20 == 10
    *x = *y - *x; // *x = 10 - (-10) == 10 + 10 == 20;
}

int main(void) {
    int x = 10, y = 20;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);

    return 0;
}