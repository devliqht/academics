#include <stdio.h>

int main(void) {
    int dec, rem, bin = 0, base = 1;
    printf("Enter a decimal number: "); scanf("%d", &dec);
    while(dec > 0) {
        rem = dec % 2;      // 16%2 = 0;    8%2 = 0;        4%2 = 0;        2%2 = 0;        1%2 = 1;
        bin += rem * base;  // 0*1 = 0;     0*10 = 0;       0*100 = 0;      0*1000 = 0;     1*10000 = 10000;
        dec /= 2;           // 16/2 = 8;    8/2 = 4;        4/2 = 2;        2/2 = 1;        1/2 = -;
        base *= 10;         // 1*10 = 10;   10*10 = 100;    100*10 = 1000;  1000*10 = 10000;1000 
    }
    /*
        First iteration: bin = 0;
        Second iteration: 
    */
    printf("Binary equivalent: %d\n", bin);
}