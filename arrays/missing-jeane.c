#include <stdio.h>

int missingNum(int *arr, int arrSize);

int main(){
    int size, arr[100];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    int miss = missingNum(arr,size);

    printf("The missing number is %d", miss);

}

int missingNum(int* arr, int arrSize) {
    int expectedSum = (arrSize * (arrSize + 1)) / 2; // Sum of first n natural numbers
    int actualSum = 0;

    for (int i = 0; i < arrSize; i++) {
        actualSum += arr[i];
    }

    return expectedSum - actualSum; // The missing number
}