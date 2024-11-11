#include <stdio.h>

void skipCounting(int, int, int);

int main(void) {
    int start, end, skip;
    printf("Start at number "); scanf("%d", &start);
    printf("End at number "); scanf("%d", &end);
    printf("Skip count by "); scanf("%d", &skip);
    
    (start >= end) ? printf("\nInvalid range!") : skipCounting(start, end, skip);
    
    return 0;
}

void skipCounting(int start, int end, int skip) {
    int count = start;
    printf("\nStart counting!\n");
    do {
        printf("%d\t", count);
        count += skip;
    } while (count <= end);
    
}