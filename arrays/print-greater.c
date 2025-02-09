#include <stdio.h>

void printGreater(int* arr, int size);

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter array values: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", arr+i);
        
    printGreater(arr, size);
}

void printGreater(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr+i);
    }
    int avg = sum / size;
    printf("Elements greater than average: ");
    for (int i = 0; i < size; i++) {
        if (*(arr+i) > avg) 
            printf("%d ", *(arr+i));
    }
}