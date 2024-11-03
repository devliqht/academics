#include <stdio.h>

int main() {
    int start = 3;
    for (int i = 0; i < 8; i++) {
        start += i;
        printf("30: %d\n", start);
    }
}