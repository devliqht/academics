#include <stdio.h>

int main(void) {
    int size = 5, first[size], second[size], third[size];
    printf("Enter first array elements:\n");
    for (int i = 0; i < size; i++) 
        scanf("%d", &first[i]);
    
    printf("Enter second array elements:\n");
    for (int j = 0; j < size; j++)
        scanf("%d", &second[j]);

    for (int k = 0; k < size; k++) {
        third[k] = first[k] + second[k];
        printf("third array element at index %d is: %d\n", k, third[k]);
    }
    return 0;
}