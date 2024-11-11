#include <stdio.h>
#define MAX 50

/*
    Enter the number of rows: 5
    Enter the number of columns: 5
    Enter the elements of the array:
    1 2 3 4 5
    6 7 8 9 10
    1 2 3 4 5
    6 7 8 9 10
    11 12 13 14 15
    Maximum element in the array is: 15
*/

int main(void) {
    int row, col, arr[MAX][MAX] = {{0}};
    
    printf("Enter the number of rows: "); scanf("%d", &row);
    printf("Enter the number of columns: "); scanf("%d", &col);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int max = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    printf("Maximum element in the array is: %d", max);
}