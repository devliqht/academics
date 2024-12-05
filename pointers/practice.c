#include <stdio.h>

int main(void) {
    float arr[] = { 1, 2, 3, 4, 5 }, *ptr = &arr[1];
    *ptr *= 2;

    for (int i = 0; i < 5; i++) {
        printf("Element arr[%d]: %.2f\n", i, arr[i]);
    }

    return 0;
}