#include <stdio.h>

int main() {
    int x, count = 1;
    printf("Enter a number: "); scanf("%d", &x);
    do {
        printf("%d*%d=%d\n", x, count, x*count);
        count++;
    } while (count <= 10);

    return 0;
}