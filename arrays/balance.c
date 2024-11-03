#include <stdio.h>
#define MAX 100

/*
    Enter the size of the array: 5
    Enter a sequence of integers:
    10
    20
    30
    40
    50
    Number of integers added to the sum: 4
*/

int main(void) {
    int n, arr[MAX], high = 100, sum = 0, count = 0;
    printf("Enter the size of the array: "); scanf("%d", &n);
    printf("Enter a sequence of integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum > 100) {
            break;
        }
        count++;
    }
    printf("Number of integers add to the sum: %d", count);

    return 0;
}