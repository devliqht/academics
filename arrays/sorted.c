#include <stdio.h>

int checkSorted(int arr[]);

int main(void) {
    int arr[10];
    printf("Enter 10 elements in the array:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    switch (checkSorted(arr)) {
        case 0:
            printf("True");
            break;
        case 1:
            printf("False");
            break;
        default:
            printf("Error");
            break;
    }
}

int checkSorted(int arr[]) {
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = i+1; j < 10; j++) {
            if (arr[i] > arr[j]) {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}