#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter array values: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < size; i++) {
        if (arr[i] <= 0) {
            printf("%d ", arr[i]);
        }
    }
    
}