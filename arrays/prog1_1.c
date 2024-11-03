#include <stdio.h>
#include <stdlib.h>

/*
    Get array size [5-100 integer range only]
    Array elements must be integer range 0-2147483647
    Choice(odd/even) caps or NO caps: character
*/

int main(void) {
    int aSize = 0;
    char choice;
    do {
        printf("Array size: ");
        scanf("%d", &aSize);
    } while (aSize < 5 || aSize > 100);

    int* arr = (int*)malloc(aSize*sizeof(int));

    printf("Input elements of array: \n");
    for (int i = 0; i < aSize; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Set of integers to display: \n");
    printf("\t[O]dd\n\t[E]ven\n");
    printf("Choice(O/E): ");
    scanf(" %c", &choice);

    if (choice == 'E' || choice == 'e') {
        printf("Even numbers: ");
        for (int i = 0; i < aSize; i++) {
            if (arr[i] % 2 == 0) {
                printf("%d ", arr[i]);
            }
        }
        puts("\n");
    } else if (choice == 'o' || choice == 'O') {
        printf("Odd numbers: ");
        for (int i = 0; i < aSize; i++) {
            if (arr[i] % 2 != 0) {
                printf("%d ", arr[i]);
            }
        }
        puts("\n");
    }

    free(arr);
    return 0;
}