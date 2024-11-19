#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter number of strings: "); 
    scanf("%d", &n);
    
    char** strings = malloc(n * sizeof(char*));
    
    for (int i = 0; i < n; i++) {
        char buffer[100];
        printf("Enter string %d: ", i + 1);
        scanf(" %s", buffer);
        strings[i] = malloc(strlen(buffer) + 1);
        strcpy(strings[i], buffer);
    }
    
    printf("\nYour strings are:\n");
    for (int i = 0; i < n; i++) {
        if (strlen(strings[i]) > 10) {
            int count = 0;
            printf("%c", strings[i][0]);
            for (int j = 1; j < strlen(strings[i])-1; j++) {
                count++;
            }
            printf("%d", count);
            printf("%c\n", strings[i][strlen(strings[i]) - 1]);
        } else {
            printf("%s\n", strings[i]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
    
    return 0;
}