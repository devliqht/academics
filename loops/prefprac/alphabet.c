#include <stdio.h>

int main(void) {
    char letter;

    while (1) {
        printf("Enter the 1st character of the alphabet: ");
        scanf(" %c", &letter);
        if (letter == 'a' || letter == 'A') {
            break;
        } else {
            continue;
        }
    }
    
    printf("\nAlphabet:\n");
    int idx = 0;
    while (idx < 26) {
        if (idx == 25) {
            printf("    %c", letter + idx);
            break;
        }
        for (int i = 0; i < 5; i++) {
            printf("%c ", letter + idx);
            idx++;
        }
        printf("\n");
    }
}