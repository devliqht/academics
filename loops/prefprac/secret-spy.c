#include <stdio.h>

void reverse(int* ptrNum) {
    int reversed = 0;
    while (*ptrNum > 0) {
        reversed = reversed * 10 + (*ptrNum % 10);
        *ptrNum /= 10;
    }
    *ptrNum = reversed;
}
int main(void) {
    int num;
    printf("Enter the number: "); scanf("%d", &num);
    reverse(&num);
    printf("%d", num);
    
    return 0;
}