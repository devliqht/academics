#include <stdio.h>

int main(void) {
    int arr[5], i = 0, j = 0, posCount = 0, negCount = 0, zerCount = 0;
    do {
        printf("Enter integer %d: ", i+1); scanf("%d", &arr[i]);
        i++;
    } while (i < 5);
    do {
        if (arr[j] > 0) {
            posCount++;
        } else if (arr[j] == 0) {
            zerCount++;
        } else {
            negCount++;
        }
        j++;
    } while (j < 5);
    printf("\nPositive count: %d\n", posCount);
    printf("Negative count: %d\n", negCount);
    printf("Zero count: %d\n", zerCount);
}