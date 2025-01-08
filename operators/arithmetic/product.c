#include <stdio.h>

int main(void) {
    int a, b;
    printf("Enter value a: ");
    printf("Enter value b: ");
    scanf("%d", &b);
    printf("Enter value b: "); scanf("%d", &b);
    int product = a * b;
    printf("Product of %d and %d is %d\n", a, b, product);

    return 0;
}