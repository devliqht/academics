#include <stdio.h>
#define MAX 100

/*
    Enter the number of elements in the array: 5
    Enter the elements of the array:
    12
    32
    25
    6
    45
    Enter the number of positions to rotate: 2
    Rotated Array: 6 45 12 32 25

*/

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
    printf("Rotated array: "); 
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

}

void rotateArray(int arr[], int size, int pos) {
    /*
        Size: 5
        0 -> 1
        1 -> 2
        2 -> 3
        3 -> 4
        4 -> 0

        Move: 2
    */
    for (int i = 0; i < pos; i++) {
        for (int j = 0; j < size - 1; j++) {
            
        }
    }
}