#include <stdio.h>

int main() {
    int n, c, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        c = 1;
        for (j = 0; j <= i; j++) { // let's say i = 2; j <= 2; 0, 1, 2
            printf("%d ", c);
            c = c * (i - j) / (j + 1);  
            // call 0: print 1; calculate c * (2-0) / (0+1) = 1 * (2/1) = 2; 
            // call 1: print 2; calculate c * (2-1) / (1+1) = 2 * (1/2) = 1;
            // call 2: print 1; 
        }
        printf("\n");
    }
    return 0;
}