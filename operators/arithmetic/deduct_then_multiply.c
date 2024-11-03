#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Enter a: "); scanf("%d", &a);
    printf("Enter b: "); scanf("%d", &b);
    printf("Enter c: "); scanf("%d", &c);
    printf("Result: %d", (a-b)*c);

    return 0;
}