#include <stdio.h>

void swapPointers(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main(void) {
    int x, y;
    printf("Enter x: "); scanf("%d", &x);
    printf("Enter y: "); scanf("%d", &y);
    printf("Before swap: %d %d\n", x, y);
    swapPointers(&x, &y);
    printf("After swap: %d %d\n", x, y);
    
    return 0;
}