#include <stdio.h>

int main(void) {
    int n;
    do {
        printf("Enter n: "); scanf("%d", &n);
    } while (n > 1 || n <= 8);

    printf("Addition Table\n");
    /*
        0   1   2   3   4   5   6   7   8
    0   0   1   2   3   4   5   6   7   8
    1   1   2   3   4   5   6   7   8   9
    2   2   3   4   5   6   7   8   9   10

    */
    
}