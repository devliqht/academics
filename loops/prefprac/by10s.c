#include <stdio.h>

void countingFunction() {
    int num;
    do {
        printf("Count from 1 up to ? "); scanf("%d", &num);
        if (num > 100 || num < 1)
            printf("Number must be between 1-100!\n");
    } while (num > 100 || num < 1);
    printf("\nCounting...\n");
    
    int i = 1, j = 0;
    do {
        do {
           printf("%d\t", i);
           i++;
           j++;
           if (i > num)
                break;
        } while (j < 10);
        printf("\n");
        j = 0;
    } while (i <= num);
}

int main(void) {
    countingFunction();
}