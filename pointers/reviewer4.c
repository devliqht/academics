#include <stdio.h>

int main(void) {
    int arr[5] = {1,3,0,4,2};
    int *ptr = arr;
    int x = arr[arr[2] * arr[0] + arr[3]];
    printf("%d and %d", x, *ptr + 5);

    return 0;
}