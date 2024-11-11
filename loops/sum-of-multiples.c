#include <stdio.h>

/*
    Write a program that asks the user to enter a positive integer n and uses a
    do-while loop to calculate the sum of all multiples of 3 or 5 below n. 
    The program should output the result.
*/

int main(void) {
    int num;
    printf("Enter a positive integer: "); scanf("%d", &num);

    int sum = 0, count = 0;
    do {
        if (count % 3 == 0 || count % 5 == 0) {
            sum += count;
        }
        count++;
    } while (count < num);

    printf("The sum of all multiples of 3 or 5 below %d is %d.", num, sum);

    return 0;
}