#include <stdio.h>

int main(void) {
    int size = 10, arr[size], odd = 0, even = 0;
    printf("Enter %d array elements:\n", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            even++;
        } else { odd++; }
    }
    printf("total even no. are: %d\n", even);
    printf("total odd number are: %d\n", odd);

    return 0;
}