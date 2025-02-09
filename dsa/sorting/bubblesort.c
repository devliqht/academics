#include <stdio.h>

void swap(int* x, int* y);
void bubbleSort(int* arr, int size);

int main(void) {
    int size;
    printf("Enter size of array: "); 
    scanf("%d", &size);
    int arr[size];
    
    printf("Enter elements of array: ");
    for (int i = 0; i < size; i++) scanf("%d", arr+i);
    
    bubbleSort(arr, size);
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < size; i++) printf("%d ", *(arr+i));
    
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int* arr, int size) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
         for (int i = 0; i < size - 1; i++) {
            if (*(arr+i) > *(arr+i+1)) {
                swap(arr+i, arr+i+1);
                swapped = 1;
            }
        }   
    }

}