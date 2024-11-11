#include <stdio.h>

/*
    Enter the size of the array: 5
    Enter the elements of the array: 1 2 3 4 5
    The second maximum value in the array is: 4
*/
int* secondMax(int arr[], int size);

int main(void) {
    int size;
    printf("Enter the size of the array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    int* secondMaxValue = secondMax(arr, size);
    (secondMaxValue != NULL) ? printf("The second maximum value in the array is: %d", *secondMaxValue) : printf("The array has less than two distinct elements.");

    return 0;
}

int* secondMax(int arr[], int size) {
    int max = arr[0], secondMaxVal = 0, *secondMaxValPtr = &secondMaxVal;
    if (size <= 2) return NULL;

    for (int i = 0; i < size - 1; i++) { // 0, 1 : 30, 15, 20;
        if (max < arr[i+1]) {
            secondMaxVal = max;
            max = arr[i+1];
        } else if (max > arr[i+1] && arr[i+1] > secondMaxVal) {
            secondMaxVal = arr[i+1];
        }
    }
    return secondMaxValPtr;
}