#include <stdio.h>

int main(void) {
    int size;
    float sum, average;
    printf("Enter the size of array:");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements of array: \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    average = sum / size;
    printf("The average of the array is: %.2f", average);
    return 0;
}