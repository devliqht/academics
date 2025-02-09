#include <stdio.h>

void reverseSubarray(int*, int, int);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int size, start, end;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", arr+i);    
    }
    printf("Enter the start index of the subarray: ");
    scanf("%d", &start);
    printf("Enter the end index of the subarray: ");
    scanf("%d", &end);
    
    printf("Before reversal: ");
    for (int i = 0; i < size; i++) printf("%d ", *(arr+i));
    reverseSubarray(arr, start, end);
    
    putchar('\n');
    printf("After reversal: ");
    for (int i = 0; i < size; i++) printf("%d ", *(arr+i));
}

void reverseSubarray(int* arr, int start, int end) {
    int leftIdx = start, rightIdx = end;
    for (int i = leftIdx, j = rightIdx; i < j; i++) {
        swap(arr+i, arr+j);
        j--;
    }
}