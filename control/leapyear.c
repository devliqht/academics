#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a year: ");
    scanf("%d", &x);

    if (x % 100 == 0) {
        if (x % 400 == 0) {
            printf("It's a leap century year.");
        } else {}
    }
}