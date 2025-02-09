#include <stdio.h>
#define MAX 100

void rotateArray(int arr[], int size, int pos);

int main(void) {
    int size, pos;
    printf("Enter the number of elements in the array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    
    printf("Enter the number of positions to rotate: "); scanf("%d", &pos);
    rotateArray(arr, size, pos);
    printf("Rotated Array: "); 
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

}

void rotateArray(int arr[], int size, int pos) {
    int temp[size];
    for (int i = 0; i < pos; i++) {
        temp[i] = arr[size-pos+i];
    }
    for (int i = size-pos-1; i >= 0; i--) {
        arr[i+pos] = arr[i];
    }
    for (int i = 0; i < pos; i++) {
        arr[i] = temp[i];
    }
}