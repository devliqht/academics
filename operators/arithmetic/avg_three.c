#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Enter three numbers: "); scanf("%d %d %d", &a, &b, &c);
    printf("Average of the three numbers: %.2f", (float)((a+b+c)/3.0f));

    return 0;
}