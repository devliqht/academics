#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* ceasarCipher(char* orig, int key);

int main(void) {
    char string[100];
    int key;
    printf("Enter a string: ");
    scanf(" %[^\n]s", string);
    printf("Enter a key: ");
    scanf("%d", &key);
    
    char* encrypted = ceasarCipher(string, key);
    printf("Encrypted string: %s", encrypted);
    
    return 0;
}

char* ceasarCipher(char* orig, int key) {
    int origLen = strlen(orig);
    char* newString = (char*)malloc((origLen+1) * sizeof(char));
    
    for (int i = 0; i < origLen; i++) {
        if (isalpha(*(orig+i)) && !isdigit(*(orig+i))) {
            char base = isupper(*(orig+i)) ? 'A' : 'a';
            *(newString+i) = ((*(orig+i) - base + key) % 26) + base;
        } else if (!isalpha(*(orig+i)) && !isdigit(*(orig+i))) {
            *(newString+i) = ' ';
        } else {
            *(newString+i) = *(orig+i);
        }
    }
    
    return newString;
}
