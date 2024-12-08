#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size of the array: "); scanf("%d", &size);
    printf("Enter elements of the array: \n");
    int arr[size];
    for (int i = 0; i < size; i++) 
        scanf("%d", &arr[i]);
    
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) count++;
    }
    
    printf("Count of even numbers in the array: %d", count);
}