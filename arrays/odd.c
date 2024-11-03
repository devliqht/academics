#include <stdio.h>
#define MAX 100
/*
    Enter size of the array: 3
    Enter elements of the array:    
    1   
    2   
    3   
    Count of odd numbers in the array: 2
*/
int main(void) {
    int n, arr[MAX] = {0};
    printf("Enter size of the array: "); scanf("%d", &n);
    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            count++;
        }
    }
    printf("Count of odd numbers in the array: %d", count);
    
}