#include <stdio.h>

void mystery(int *ptra, int* ptrb) {
    int *temp;
    temp = ptrb;
    ptrb = ptra;
    ptra = temp;
}

int main(void) {
    int a = 2016, b = 0, c = 4, d = 42;
    mystery(&a, &b);
    if (a < c) mystery(&c, &a);
    mystery(&a, &b);
    printf("%d", a); // 2016

    return 0;
}