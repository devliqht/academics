#include <stdio.h>

int main(void) {
    int arr[5] = { 1, 3, 0, 4, 2 };
    int* ptr;

    ptr = arr + 2; // 0 arr[2]
    printf("ptr: %d ", *ptr);

    printf("arr[*ptr]: %d ", arr[*ptr]); // arr[0] == 1

    printf("*(ptr+2): %d ", *(ptr+2)); // arr+2+2 == 2
    return 0;
}