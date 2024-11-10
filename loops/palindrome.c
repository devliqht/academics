#include <stdio.h>

int main(void) {
    int num;
    printf("Enter a number: "); scanf("%d", &num);
    int orig = num, reversed = 0;
    for (num; num > 0; num /= 10) {
        int lastDigit = num % 10;
        reversed = reversed * 10 + lastDigit; 
    }
    (orig == reversed) ? printf("%d is a palindrome number", orig) : printf("%d is not a palindrome number", orig);

    return 0;
}