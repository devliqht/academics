#include <stdio.h>

int main(void) {
    int m = 29, *ab = &m;
    printf("Address of m: %p\n", &m);
    printf("Value of m: %d\n", m);
    printf("Address of pointer ab: %p\n", ab);
    printf("Content of pointer ab: %d\n\n", *ab);

    m = 34;
    printf("Address of pointer ab: %p\n", ab);
    printf("Content of pointer ab: %d\n\n", *ab);

    *ab = 7;
    printf("Address of m: %p\n", &m);
    printf("Value of m: %d", m);

    return 0;
}