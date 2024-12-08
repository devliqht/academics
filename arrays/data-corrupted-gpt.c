#include <stdio.h>

int main() {
    int size;

    // Ask for the size of the array
    printf("Input how many items in the array: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("Oh no Data is fully corrupted and cannot be recovered!\n");
        return 0;
    }

    int array[size];
    int cleanedArray[size];
    int cleanedCount = 0;

    // Populate the array with user input
    printf("Input Array Values: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Filter the array to clean it
    for (int i = 1; i < size - 1; i++) {
        if (array[i - 1] != -1 && array[i + 1] != -1) {
            cleanedArray[cleanedCount++] = array[i];
        }
    }

    // Check if data has been cleaned
    if (cleanedCount > 0) {
        printf("Data has been recovered!\n");
        printf("Cleaned Data: ");
        for (int i = 0; i < cleanedCount; i++) {
            printf("%d ", cleanedArray[i]);
        }
        printf("\n");
    } else {
        printf("Oh no Data is fully corrupted and cannot be recovered!\n");
    }

    return 0;
}
