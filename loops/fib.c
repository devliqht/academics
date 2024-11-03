#include <stdio.h>

int main() {
    int terms, count = 2, sum = 1, fibBef = 0, fibAft = 1;
    printf("Enter the number of terms: "); scanf("%d", &terms);
    printf("Fibonacci Series: 0 1 ");
    
    while (count < terms) { // 0 1 1 2 3 5 8 13 21 34 55
        fibBef = fibAft; // 3
        fibAft = sum; // 5
        printf("%d ", sum);
        sum = fibBef + fibAft; // 8
       
        count++;
    }
}