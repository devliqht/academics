#include <stdio.h>

int main(void) {
    int size, sum = 0, count = 0;
    printf("Enter the number of elements: "); scanf("%d", &size);
    int arr[size];
    printf("Enter %d numbers: \n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        count++;
        if (arr[i] % 2 == 0) {
            sum += arr[i];     
        }
        if (sum > 100)
            break;
    }
    printf("Sum of even numbers: %d", sum);
}