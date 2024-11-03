#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter value a: "); scanf("%d", &a);
    printf("Enter value b: "); scanf("%d", &b);
    printf("Product of %d and %d is %d", a, b, a*b);

    return 0;
}