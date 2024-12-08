#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    printf("Enter elements of array: \n");
    int arr[size];
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    
    int min = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Minimum element in array is: %d", min);
}