#include <stdio.h>

void doubleTheGreatest(int* arr, int size);

int main(void) {
    int n;
    printf("Enter the number of elements: "); 
    scanf("%d", &n);
    
    int array[n];
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", array+i);
    }
    printf("Before doubling: ");
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
    putchar('\n');
    
    printf("After doubling: ");
    doubleTheGreatest(array, n);
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
}

void doubleTheGreatest(int* arr, int size) {
    int* greatest = arr;
    for (int i = 1; i < size; i++) {
        if (*(arr+i) > *greatest) {
            greatest = arr+i;
        }
    }
    *greatest *= 2;
}