#include <stdio.h>

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    int mid = n / 2;

    for (int i = 0; i <= mid; i++) {
        for (int j = 0; j < n; j++) {
            if (j == mid - i || j == mid + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    for (int i = mid - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (j == mid - i || j == mid + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
