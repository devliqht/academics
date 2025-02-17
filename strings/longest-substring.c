#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int lengthOfLongestSubstring(char*);

int main(void) {
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    printf("Length of longest substring without repeating characters: %d", lengthOfLongestSubstring(str));
    
    return 0;
}

int lengthOfLongestSubstring(char* str) {
    int len = strlen(str);
    int longest = 0;
    int start = 0;
    
    for (int i = 0; i < len; i++) {
        for (int j = start; j < i; j++) {
            if (str[j] == str[i]) {
                start = j+1;
                break;
            }
        }
        
        int currentLen = i - start + 1;
        if (currentLen > longest) {
            longest = currentLen;
        }
    }
    
    return longest;
}