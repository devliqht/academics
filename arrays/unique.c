#include <stdio.h>

int uniqueElementCount(int arr[], int arrSize);

int main(void) {
    int size;
    printf("Enter size of array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter array values: \n");
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
    
    printf("Number of unique elements: %d", uniqueElementCount(arr, size));
}

int uniqueElementCount(int arr[], int arrSize) {
    int unique = 0;
    for (int i = 0; i < arrSize; i++) {
        int isUnique = 1;
        for (int j = 0; j < arrSize; j++) {
            if (arr[i] == arr[j] && i != j) { 
                /*
                    {1, 1, 2, 3, 4 }
                    First call: arr[0]: 1 == arr[0]: 1 && i == j: FALSE
                    Second call: arr[1]: 1 == arr[0]: 1 && i /= j: TRUE
                    Third call: arr[2]: 2 == arr[0]: 1 FALSE
                    arr[2] == arr[1]: 1 FALSE

                */
                isUnique = 0;
                break;
            }
        }
        if (isUnique) unique++;
    }
    return unique;
}