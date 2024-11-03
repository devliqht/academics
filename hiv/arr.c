#include <stdio.h>
#include <stdlib.h>


int main() {
    int x, sum = 0;;
    printf("Enter the number of elements: "); scanf("%d", &x);
    printf("Enter the elements:\n");
    int* arr = (int*)malloc(x*sizeof(int));
    for (int i = 0; i < x; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum of elements: %d", sum);
    free(arr);
    return 0;
}