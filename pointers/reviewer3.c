#include <stdio.h>

int recur(int num) {
    num = num%4;
    switch (num) {
        case 1: return recur(num/4); break;
        case 2: return recur(num+4); break;
        case 3: return recur(num * 4); break;
        default: return num - 4;
    }
}

int main(void) {
    int num = 11;
    int x = recur(num);
    printf("%d", x);
}