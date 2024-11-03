#include <stdio.h>

int sumUpTo(int n);

int main(void) {
    int n;
    printf("Enter a number: "); scanf("%d", &n);
    printf("Sum: %d", sumUpTo(n));
}
/*
    First call: sumUpTo(5) = 5 + sumUpTo(4)
    Second call: sumUpTo(4) = 4 + sumUpTo(3)
    Third call: sumUpTo(3) = 3 + sumUpTo(2)
    Fourth call: sumUpTo(2) = 2 + sumUpTo(1)
    Fifth call: sumUpTo(1) = 1

    sumUpTo(5) = 5 + sumUpTo(4) = 5 + 4 + sumUpTo(3) = 5 + 4 + 3 + sumUpTo(2) = 5 + 4 + 3 + 2 + sumUpTo(1) = 5 + 4 + 3 + 2 + 1
*/
int sumUpTo(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumUpTo(n-1);
}