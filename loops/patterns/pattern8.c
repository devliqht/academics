#include <stdio.h>

int main(void) {
    int space = 4;
    for (int i = 1; i <= 5; i++) {
        for (int k = 0; k < space; k++) {
            printf("  ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        for (int j = i-1; j >= 1; j--) {
            printf("%d ", j);
        }
        space--;
        printf("\n");
    }
    
    for (int i = 5; i > 0; i--) {
        for (int k = 5; k > i-1; k--) {
            printf("  ");
        }
        for (int j = 1; j < i; j++) { 
            printf("%d ", j);
        }
        for (int j = i-2; j >= 1; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}