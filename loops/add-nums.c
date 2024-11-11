#include <stdio.h>

int getNums();

int main(void) {

    printf("Please enter numbers: \n");
    int sum = getNums();

    printf("The sum of the numbers are: %d", sum);

    return 0;
}

int getNums() {
    int sum = 0, num, i = 1;
    while (num >= 0) {
        num = 0;
        printf("[%d]: ", i);
        scanf("%d", &num);
        if (num >= 0) {
            sum = sum + num;
        } else {
            break;
        }
        i++;
    }

    return sum;
}