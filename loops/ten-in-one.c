#include <stdio.h>

/*
    A program that counts from 0-50 with 10 numbers per line.
    A user will enter a size of numbers, and the program will count from 0-50
    and display "Numbers must be below 50!" if the size exceeds or equal to 50.
    The values are guaranteed to be positive integers.
    First message is a prompt to enter size.
*/

void count(int size);

int main(void) {
    int size;

    printf("Please enter size: ");
    scanf("%d", &size);

    count(size);

    return 0;
}

void count(int size) {
    int i, j = 1, track = 10;
    for (i = 1; i <= (size/10); i++) {
        while (j <= track) {
            printf("%d ", j);
            j++;
            if (j >= 50) {
                printf("\nNumbers must be below 50!");
                break;
            }
        }
        printf("\n");
        track += 10;
        if (track > 50) {
            break;
        }
    }
}