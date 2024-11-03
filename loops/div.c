#include <stdio.h>

void displayFive(int n);

int main(void) {
    int num;

    printf("Please enter a number: ");
    scanf("%d", &num);

    displayFive(num);
    return 0;
}

void displayFive(int n) {
    for (int i = 0; i <= n; i++) {
        if ((i % 5) == 0) {
            printf("%d ", i);
        }
    }
}