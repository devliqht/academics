#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char* reverseString(char* string);

int main(void) {
    char str[MAX];
    printf("Enter string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    char* reversed = reverseString(str);
    if (reversed != NULL) {
        printf("Reversed String: %s", reversed);
    }
    
    free(reversed);
    
    return 0;
}

char* reverseString(char* string) {
    int len = strlen(string);
    char* reversed = (char*)malloc((len+1) * sizeof(char));
    if (reversed == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    int end = -1, start = -1, j = 0;
    
    for (int i = len - 1; i >= 0; i--) {
        if (string[i] != ' ' && end == -1) {
            end = i;
        }
        if ((string[i] == ' ' || i == 0) && end != -1) {
            start = (string[i] == ' ') ? i+1 : i;
            for (int k = start; k <= end; k++) {
                reversed[j++] = string[k];
            }
            reversed[j++] = ' ';
            end = -1;
        }
    }
    reversed[j - 1] = '\0';
    
    return reversed;
}