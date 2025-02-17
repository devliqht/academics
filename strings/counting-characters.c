#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void removeSpaces(char* string);
void countCharacters(const char* string);

int main(void) {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    countCharacters(str);
    
    return 0;
}

void countCharacters(const char* string) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < strlen(alphabet); i++) {
        int j;
        int occurences = 0;
        for (j = 0; j < strlen(string); j++) {
            if (alphabet[i] == string[j]) {
                occurences++;
            }
        }
        if (occurences > 0) {
            printf("%c: %d\n", alphabet[i], occurences);
        }
    }
}