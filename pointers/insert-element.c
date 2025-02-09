#include <stdio.h>
#define MAX 100

void insertElement(int* arr, int* size, int index, int value);
void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int arr[MAX];
    int size, idx, val;
    printf("Enter the size of the array: "); scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) scanf("%d", arr+i);
    
    printf("Enter the index where you want to insert the element: ");
    scanf("%d", &idx);
    
    if (idx < 0 || idx > size) {
        printf("Invalid index.\n");
        return 0;
    }
    
    printf("Enter the value you want to insert: ");
    scanf("%d", &val);
    
    insertElement(arr, &size, idx, val);
    printf("The modified array is: ");
    for (int i = 0; i < size; i++) printf("%d ", *(arr+i));
    
    return 0;
}

void insertElement(int* arr, int* size, int index, int value) {
    for (int i = *size - 1; i >= index; i--) {
        *(arr+i+1) = *(arr+i);
    }
    *(arr+index) = value;
    (*size)++;
}
