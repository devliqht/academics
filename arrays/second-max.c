#include <stdio.h>
#include <limits.h>

int secondLargest(int arr[], int size) {
    if (size < 2) return -1;
    
    int largest = arr[0], second = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) { // largest = -1, second = 0. arr[1] > -1: FALSE
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }
    
    return second;
}

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter array values: \n"); 
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    
    (secondLargest(arr, size) != -1) ? printf("The second largest element is: %d", secondLargest(arr, size)) : printf("Array is too small to have a second largest element.");
}