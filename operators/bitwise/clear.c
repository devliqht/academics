#include <stdio.h>

int main() {
    int num, pos;
    printf("Enter value of num: "); scanf("%d", &num);
    printf("Enter bit position to clear: "); scanf("%d", &pos);
    
    // 0000100000 = bitmask
    int bitmask = 1 << pos;
    
    // 1100010010 = 786

    // 1111011111 = updated bitmask
    
    // 1100010010 wow tf why am i so smart
    
    
    printf("Result: %d", num & (~bitmask));

    return 0;
}