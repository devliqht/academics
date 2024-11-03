#include <stdio.h>
/*
    Matt Erron G. Cabarrubias
    CIS 1101 Group 11
*/
int main(void) {
    while (1) {
        int num;
        printf("Enter a number: "); scanf("%d", &num);
        if (num == 0) continue;
        if (num > 0) {
            printf("Positive Value\n");
            break;
        } else {
            if (num % 2 != 0) {
                printf("%d\n", num);
            } else {
                printf("Amazing negative Value\n");
            }
        }
    }
}