#include <stdio.h>

int main(void) {
    int count = 1;
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", count);
            count++;
        }
        printf("\n");
        
    }
}

/*
1 
2 3
4 5 6
7 8 9 10
11 12 13 14 15
*/