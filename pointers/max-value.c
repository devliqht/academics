#include <stdio.h>

/*
Enter the size of the array: 5
Enter 5 integers:
1 2 3 4 5
Maximum value in the array is: 5
*/
int* maxValue(int* arr, int size) {
    int* max = &arr[0];
    for (int i = 1; i < size; i++) {
        if (*max < arr[i]) {
            max = &arr[i];
        }
    }
    return max;
}

int main(void) {
    int size;
    printf("Enter the size of the array: "); scanf("%d", &size);
    printf("Enter %d integers: \n", size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    int* maxVal = maxValue(arr, size);
    printf("Maximum value in the array is: %d", *maxVal);

    return 0;

}