#include <stdio.h>

int main(void) {
    int n = 10, k = n;
    for (int i = 0; i < n/2; i++) { // i = 4 is full; i = 5
        for (int j = 0; j < n; j++) { // 0 <= 5, 1 <= 5, 2 <= 5, 3 <= 5, 4 <= 5, 5 <= 5, 6 >=
            if (j <= i || j >= k-1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        k--; // 9, 8, 7, 6
        printf("\n");
    }
    k = n / 2 + 1; 
    for (int i = n / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (j < i || j > k - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        k++; 
        printf("\n");
    }
}