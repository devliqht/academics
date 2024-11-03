#include <stdio.h>

int main(void) {
    int num;

    printf("Enter range (from 1 to): ");
    scanf("%d",&num);

    for (int i = 1; i <= num; i++) {
        int count = 0;
        printf("Number [%d]: \n", i);
        for (int j = 1; j <= num; j++) {
            if (i % j == 0) {
                printf("\tFactor: %d\n", j);
                count++;
            }
        }
        if (count == 2) {
            printf("\tThis number is a prime number. \n");
        }
    }
    return 0;
}