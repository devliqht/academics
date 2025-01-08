#include <stdio.h>

/*
1 2 3 
8 9 4
7 6 5

[0][0] [0][1] [0][2] startRow = 0 : if startCol < endCol, stop, set startCol to endCol
[1][2] [2][2] [2][1] startRow = 1 : if startRow < endRow, stop, minus endCol 
[2][0] [1][0] [1][1]
*/

int main(void) {
    int size;
    printf("Enter matrix size: "); scanf("%d", &size);
    int spiral[size][size], startCol = 0, startRow = 0, endCol = size - 1, endRow = size - 1;
    
    int count = 1;
    while (startRow <= endRow && startCol <= endCol) {
        for (int i = startCol; i <= endCol; i++) {
            spiral[startRow][i] = count++;
        }
        startRow++;
        
        for (int i = startRow; i <= endRow; i++) {
            spiral[i][endCol] = count++;
        }
        endCol--;
        
        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; i--) {
                spiral[endRow][i] = count++;
            }
            endRow--;
        }
        
        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; i--) {
                spiral[i][startCol] = count++;
            }
            startCol++;
        }
    }
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", spiral[i][j]);
        }
        printf("\n");
    }

}