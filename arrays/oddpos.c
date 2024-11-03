#include <stdio.h>
#include <string.h>
/*
    Write a program that takes a string input from the user and prints all characters at odd positions, 
    skipping all characters at even positions.
*/

int main(void) {
    char str[100];
    printf("Enter a string: "); fgets(str, sizeof(str), stdin);
    for (int i = 1; i < strlen(str) - 1; i++) {
        if (i % 2 == 0) {
            continue;
        }
        printf("%c", str[i]);
    }
}