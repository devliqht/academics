#include <stdio.h>

void selection_sort(int* arr, int size);

int main(void) {
    int arr[] = {8,3,5,1,2,6,7,4};
    selection_sort(arr, 8);
    
    return 0;
}

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(int* arr, int size) {
    int i, j, smallest;

    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        smallest = i;

        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[smallest]) {
                smallest = j;
                swapped = 1;
            }
        }
        swap(arr+i, arr+smallest);

        if (!swapped) break;
        printf("pass %d: \n", i+1);
        for (int i = 0; i < size; i++) {
            printf("%d ", *(arr+i));
        }

        putchar('\n');
    }
}