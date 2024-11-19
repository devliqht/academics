#include <stdio.h>
#include <math.h>

/*
Enter size of array: 5
Enter elements of array: 1 2 3 4 5
Middle element of array is: 3
*/
int* midElem(int* arr, int size) {
    int* midPtr = &arr[size/2];
    if (size % 2 == 0) {
        midPtr--;
    }    
    return midPtr;
}
int main(void) {
    int size, *midPtr;
    printf("Enter size of array: "); scanf("%d", &size);
    printf("Enter elements of array: ");
    
    int arr[size]; 
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    midPtr = midElem(arr, size);
    printf("Middle element of array is: %d", *midPtr);

    return 0;
}