#include <stdio.h>
#include <math.h>
#define MAX 100

int main(void) {
    int n, arr[MAX] = {0};
    printf("Enter the number of elements in the array: "); scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    
    printf("Perfect square elements in the array: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            int sqrtn = (int)sqrt(arr[i]);
            if (arr[i] == (sqrtn*sqrtn))
                printf("%d ", arr[i]);
        }
    }
}