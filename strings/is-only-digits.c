#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

bool isOnlyDigits(const char* string);

int main(void) {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    (isOnlyDigits(str)) ? printf("The string contains only digits.") : printf("The string does not contain only digits.");
    
    return 0;
}

bool isOnlyDigits(const char* string) {
    for (int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i])) {
            return false;
        } 
    }
    
    return true;
}