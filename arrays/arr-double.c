#include <stdio.h>
#include <stdlib.h>

int* doubledArray(int arr[], int arrSize);

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter array values: \n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    printf("Doubled array: \n");
    
    int* doubled = doubledArray(arr, size);
    for (int i = 0; i < size; i++) printf("%d ", *(doubled+i));
    
    return 0;
}

int* doubledArray(int arr[], int arrSize) {
    int* doubleArr = (int*)malloc(arrSize*sizeof(int));
    for (int i = 0; i < arrSize; i++) {
        *(doubleArr+i) = arr[i] * 2;
    }
    return doubleArr;
}