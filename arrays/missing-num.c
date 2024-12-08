#include <stdio.h>

int missingNumber(int* arr, int arrSize);

int main(void) {
    int size;
    printf("Enter the size of array: "); scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter element: "); scanf("%d", &arr[i]);
    }
    printf("The missing number is: %d", missingNumber(arr, size));
}

int missingNumber(int* arr, int arrSize) {
    int missing = 0;
    if (arrSize > 1) {
        for (int i = 0; i < arrSize - 1; i++) {
            if ((arr[i] + 1) != arr[i+1]) {
                missing = arr[i] + 1;
            }
        }
    } else { 
        missing = arr[0] - 1;
    }
    return missing;
}