#include <stdio.h>

void bandalan_sort(int* arr, int size);

int main(void) {
    int arr[] = {8,3,5,1,2,6,7,4};
    bandalan_sort(arr, 8);
    
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int* arr, int size) {
    int i, j, biggest;

    for (i = 0; i < size - 1; i++) {
        biggest = 0;

        for (j = 0; j < size - i; j++) { 
            if (arr[j] > arr[biggest]) {
                biggest = j;
            }
        }

        printf("swap: %d --> %d\n", arr[size-1-i], arr[biggest]);
        swap(&arr[size - 1 - i], &arr[biggest]);
        printf("pass %d: \n", i+1);
        for (int k = 0; k < size; k++) {
            printf("%d ", *(arr+k));
        }

        putchar('\n');
        putchar('\n');
    }
}