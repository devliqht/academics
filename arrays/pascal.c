#include <stdio.h>
#include <stdlib.h>

/*  TEST CASE
    Enter the number of rows: 5
    Pascal's triangle: 
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    1 5 10 10 5 1
    1 6 15 20 15 6 1

    [0][0]
    

    1 1 1 1 1 
    1 2 3 4 
    1 3 6
    1 4
    1

*/
int createSize(int rows);
void createPascal(int rows);

int main() {
    int rows;
    printf("Enter the number of rows: "); scanf("%d", &rows);
    createPascal(rows);
}

int createSize(int rows) {
    int size = 0;
    for (int i = rows; i > 0; i--) {
        size += i;
    }
    return size;
}

void createPascal(int rows) {
    int pascalTriangle[rows][rows];
    
    for (int h = 0; h < rows; h++) {
        for (int j = 0; j < rows; j++) {
            pascalTriangle[h][j] = 1;
        }
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < rows; j++) { 
            if (pascalTriangle[i][j] == 1) {
                pascalTriangle[i][j] = (pascalTriangle[i-1][j] + pascalTriangle[i][j-1]);
            }
        }
    }
    for (int sum = 0; sum < rows; sum++) { 
        for (int k = rows - sum; k > 0; k--) {
            printf(" ");
        }
        for (int i = 0; i <= sum; i++) { 
            int j = sum - i;
            if (j < rows) {
                printf("%d ", pascalTriangle[i][j]);
            }
        }
        printf("\n");
    }
}
