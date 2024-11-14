#include <stdio.h>

int main(void) {
    int size;
    printf("Enter the size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int revArr[size], newSize = size;
    for (int i = 0; i < size; i++) {
        revArr[i] = arr[newSize-1];
        newSize--;
    }
    printf("The array in reverse order is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", revArr[i]);
    }
    return 0;
}