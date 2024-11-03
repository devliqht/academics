#include <stdio.h>

int main(void) {
    int n;
    printf("Enter the value of n: "); scanf("%d", &n);
    
    int k = n;
    for (int i = 0; i < n; i++) {
        int count = n;
        for (int j = 0; j < n; j++) {
            if (k % 2 != 0) {
                (count % 2 != 0) ? printf("W ") : printf("B ");
            } else {
                (count %2 != 0) ? printf("B ") : printf("W ");
            }
            count--;
        }
        printf("\n");
        k--;
    }
}