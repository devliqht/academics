#include <stdio.h>

int main(void) {
    int dividend, divisor;

    printf("Enter dividend: "); scanf("%d", &dividend);
    printf("Enter divisor: "); scanf("%d", &divisor);
    printf("Quotient = %d", dividend/divisor);

    return 0;
}