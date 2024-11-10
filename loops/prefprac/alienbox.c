#include <stdio.h>

int main(void) {
    int num;
    printf("Enter a number: "); scanf("%d", &num);
    if (num < 2) {
        printf("Invalid input!");
        return 0;
    }
    
    int i = 1, j = 0;
    while (i <= num) {
        while (j < num) {
            if (j == num-1) {
                printf("%d ", i+1);       
            } else {
                printf("%d ", i);
            }
            j++;
        }
        printf("\n");
        j = 0;
        i++;
    }
}