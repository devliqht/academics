#include <stdio.h>

int main() {
    int i = 5;
    int count = 0;
    do {
        i--;
        count++;
        printf("iteration: %d\n", count);
    } while (i > 0);
    return 0;
}