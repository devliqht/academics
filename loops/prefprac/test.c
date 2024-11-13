#include <stdio.h>

int main(void) {
    int i = 5, it = 0;
    do {
        i--; it++;
        printf("iteration: %d", it);
    } while (i > 0);
    return 0;
}