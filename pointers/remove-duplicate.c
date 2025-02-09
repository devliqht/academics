#include <stdio.h>

void removeDuplicate(int* arr, int* size);

int main(void) {
    int size;
    
    printf("Enter the size of the array: "); scanf("%d", &size);
    int arr[size];
    
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) scanf("%d", arr+i);
    
    removeDuplicate(arr, &size);
    printf("The unique elements in the array are: ");
    for (int i = 0; i < size; i++) printf("%d ", *(arr+i));
}

void removeDuplicate(int* arr, int* size) {
    for (int i = 0; i < *size - 1; i++) {
        for (int j = i + 1; j < *size;) {
            if (*(arr+i) == *(arr+j)) {
                for (int k = j; k < *size - 1; k++) {
                    *(arr+k) = *(arr+k+1);
                }
                (*size)--;
            } else {
                j++;
            }
        }
    }
}