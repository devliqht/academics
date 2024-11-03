#include <stdio.h>

/*
    Enter the size of the matrix: 3
    Enter the elements of the matrix:
    1 2 3
    4 5 6
    7 8 9
    The diagonal sum of the matrix is: 15
*/

int main(void) {
    int size, sum = 0;
    printf("Enter the size of the matrix: "); scanf("%d", &size);
    int matrix[size][size];
    printf("Enter the elements of the matrix: \n");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }

    printf("The diagonal sum of the matrix is: %d", sum);

    return 0;
}