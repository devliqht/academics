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
    int spiral[size][size], startCol = 0, startRow = 0, endCol = size, endRow = size;
    
    int count = 1;
    for(int i = 0; i < size; i++) {
        for (int j = startCol; j < endCol; j++) {
            printf("%d ", count);
            if (j < endCol) {
                startCol = endCol;
            }
            count++;
        }
    }

}