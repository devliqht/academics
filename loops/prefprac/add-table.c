#include <stdio.h>

void additionTable(int);

int main(void) {
    int n;
    do {
        printf("Enter n: "); scanf("%d", &n);
    } while (n < 1 || n > 8);
    
    additionTable(n);

}

void additionTable(int n) {
    printf("\nAddition Table\n\t");
    
    for (int i = 0; i <= n; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i <= n; i++) {
        printf("%d\t", i);
        for (int j = i; j <= n+i; j++) {
            printf("%d\t", j);
        }
        printf("\n");
    }
}