#include <stdio.h>

int main(void) {
    unsigned int n;
    int count = 0;
    printf("Enter n: "); scanf("%u", &n);
    while (n > 0) {
        if (n%10 > 3) {
            printf("%u\n", n%10);        
            count++;
        }
        n /= 10;
    }
    if (count == 0)
        printf("none");
    
    return 0;
}