#include <stdio.h>

int main(void) {
    int elemNum, sum = 0;
    printf("Enter the number of elements: "); scanf("%d", &elemNum);
    int arr[elemNum];
    printf("Enter the elements:\n");
    for (int i = 0; i < elemNum; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum of array elements: %d", sum);
    return 0;
}