#include <stdio.h>
#include <math.h>

int main(void) {
    int size;
    printf("Enter the number of elements in the array: "); scanf("%d", &size);
    printf("Enter the elements of the array: \n");
    int arr[size];
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    
    int perfCount = 0;
    for (int k = 0; k < size; k++) {
        int root = sqrt(arr[k]);
        if ((root * root) == arr[k]) perfCount++;
    }
    
    int perfArr[perfCount], perfIdx = 0;
    for (int j = 0; j < size; j++) {
        int root = sqrt(arr[j]);
        if ((root * root) == arr[j]) {
            perfArr[perfIdx] = arr[j];
            perfIdx++;
        }
    }
    
    printf("Perfect square elements in the array: ");
    for (int i = 0; i < perfIdx; i++) {
        printf("%d ", perfArr[i]);
    }
}