#include <stdio.h>
#include <math.h>

int isPalindrome(int num);
int convertToBinary(int num);

int main(void) {
    int num;
    printf("Enter your number: "); scanf("%d", &num);
    int bin = convertToBinary(num);
    printf("The value of your soul is %d\n", bin);
    (isPalindrome(bin)) ? printf("You are worthy my child.") : printf("Ahh, you are filty. Be gone.");

    return 0;
}

int isPalindrome(int num) {
    int orig = num, reversed = 0;
    while (num > 0) {
        int lastDigit = num % 10;
        reversed = reversed * 10 + lastDigit; 
        num /= 10;
    }
    return orig == reversed;
}

int convertToBinary(int num) {
    int place = 1, binary = 0;
    while (num > 0) {
        binary += (num%2) * place;
        num /= 2;
        place *= 10;
    }
    return binary;
}