#include <stdio.h>

int main(void) {
    int rows;
    printf("Enter number of rows: "); scanf("%d", &rows);

    int i = 1, j;
    do {
        for (j=rows;j>i;j--) { // Rows: 5, j = 5; j > 1; 5, 4, 3, 2
            printf(" ");
        }
        for (j=1;j<(2*i);j++) { // Rows: 5, j = 1; j < 1, j < 4; 1
            printf("*");
        }
        printf("\n");
        i++;
    } while (i < rows);
    
    for (int k = 0; k < rows+(rows-1); k++) {
        printf("*");
    } printf("\n");

    i = rows-1; // 4, 3, 2, 1
    do {
        for (j=i;j<rows;j++) { 
            printf(" ");
        }
        for (j=1;j<(2*i);j++) {
            printf("*");
        }
        printf("\n");
        i--;
    } while (i > 0);
  
    return 0;
}