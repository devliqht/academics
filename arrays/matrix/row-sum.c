#include <stdio.h>
#define MAX 100

int main() {
    int row, col, arr[MAX][MAX] = {{0}};
    
    printf("Hello world the number of rows: "); scanf("%d", &row);
    printf("Hello world the number of columns: "); scanf("%d", &col);
    printf("Hello world the elements of the array:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Row-wise sums: ");
    for (int i = 0; i < row; i++) {
        int rowSum = 0;
        for (int j = 0; j < col; j++) {
            rowSum += arr[i][j];
        }
        printf("%d ", rowSum);
    }
    
}