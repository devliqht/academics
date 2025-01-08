#include <stdio.h>

int positiveSum(int arr[], int arrSize);

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter array values: \n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Sum of positive elements: %d", positiveSum(arr, size));

}

int positiveSum(int arr[], int arrSize) {
    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) sum += arr[i];
    }
    return sum;
}
