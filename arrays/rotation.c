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

void rotateArray(int arr[], int n, int k);

int main(void) {
    int n, k, arr[MAX] = {0};
    printf("Enter the number of elements in the array: "); scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    
    printf("Enter the number of positions to rotate: "); scanf("%d", &k);
    rotateArray(arr, n, k);
    
    printf("Rotated Array: ");
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    return 0;
}

void rotateArray(int arr[], int n, int k) {

}