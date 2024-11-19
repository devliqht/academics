#include <stdio.h>

/*
Enter the size of the array: 5
Enter the elements of the array: 1 2 3 4 5
The sum of the elements in the array is: 15
*/

int sumOfArr(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr+i);
    }
    return sum;
}

int main(void) {
    int size;
    printf("Enter the size of the array: "); scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array: "); 
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sum = sumOfArr(arr, size);
    printf("The sum of the elements in the array is: %d", sum);

    return 0;

}