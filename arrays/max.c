#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter elements of array: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
        
    int max = arr[0];
    for (int k = 1; k < size; k++) {
        if (arr[k] > max) {
            max = arr[k];
        }
    }
    printf("Maximum element in array is: %d", max);
}