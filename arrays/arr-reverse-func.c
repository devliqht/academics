#include <stdio.h>

void arrReverse(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) printf("%d ", arr[i]);
}

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter array values:\n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    arrReverse(arr, size);
    
    return 0;
}