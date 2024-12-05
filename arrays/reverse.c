#include <stdio.h>

void reverse(int arr[], int size);
void swap(int* x, int* y);

int main(void) {
    int size;
    printf("Enter the number of elements: "); scanf("%d", &size);
    int arr[size];
    printf("Enter the elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    reverse(arr, size);
    printf("Reversed array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(&arr[i], &arr[size - i - 1]); // 0 -> 4, // 1 -> 3
    }
}