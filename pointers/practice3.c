#include <stdio.h>

int findMax(int arr[], int size) {
    int* max = arr;
    for (int i = 0; i < size; i++) {
        if (*max < *(arr+i)) {
            max = &arr[i];
        }
    }
    return *max;
}

int main(void) {
    int arr[] = { 3, 1, 4, 5, 9, 2, 6 };
    

    printf("Maximum element: %d", findMax(arr, 7));
}