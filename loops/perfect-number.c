#include <stdio.h>

int main() {
    int num;
    printf("Enter the value of n: "); scanf("%d", &num);
    printf("Perfect numbers up to %d:\n", num);

    for (int i = 1; i <= num; i++) { // 6
        int sum = 0;
        for (int j = 1; j < i; j++) { 
            if (i % j == 0) {  // ex: 6; 6 % 1, 6 % 2, 6 % 3 = 1 + 3 + 2
                sum += j;
            }
        }
        if (sum == i) {
            printf("%d\n", i);
        }
    }
}