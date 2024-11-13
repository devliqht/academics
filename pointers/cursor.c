#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows;
    printf("\nEnter number of rows: ");
    scanf("%d", &rows);

    int **triangle = (int **)malloc(rows * sizeof(int *));
    
    for (int i = 0; i < rows; i++) {
        triangle[i] = (int *)malloc((i+1) * sizeof(int));
        
        *(*(triangle + i) + 0) = 1;
        *(*(triangle + i) + i) = 1;
        
        for (int j = 1; j < i; j++) {
            *(*(triangle + i) + j) = *(*(triangle + i-1) + j-1) + *(*(triangle + i-1) + j);
        }
    }
    
    printf("\nPascal's Triangle:\n");
    for (int i = 0; i < rows; i++) {
        for (int space = 0; space < rows-i-1; space++) {
            printf("  ");
        }
        
        for (int j = 0; j <= i; j++) {
            printf("%4d", *(*(triangle + i) + j));
        }
        printf("\n");
    }
    
    for (int i = 0; i < rows; i++) {
        free(triangle[i]);
    }
    free(triangle);
    return 0;
}