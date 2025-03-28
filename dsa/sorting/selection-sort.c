#include <stdio.h>

void selection_sort(char* arr, int size);

int main(void) {
    char str[] = "ABCDE";
    selection_sort(str, 5);
    
    return 0;
}

void swap(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(char* arr, int size) {
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
            printf("%c ", *(arr+i));
        }

        putchar('\n');
    }
}