#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[100], vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
    printf("Enter a string: "); fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    int count = strlen(str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            for (int j = 0; j < 5; j++) {
                if (tolower(str[i]) == vowels[j]) {
                    count--;
                    printf("Vowel: %c\n", str[i]);
                }
            }     
        } else {
            count--;
            continue;
        }

    }
    printf("Number of consonants: %d\n", count);
    return 0;
}