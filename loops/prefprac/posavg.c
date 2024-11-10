#include <stdio.h>

double getNumber() {
    double num;
    scanf("%lf", &num);
    return num;
}

void showElements(double arr[], int size) {
    printf("\nArray elements:\n");
    for (int i = 0; i < size; i++) {
        printf("[%d] = %.2lf\n", i, arr[i]);
    }
}

int main(void) {
    int size, idx = 0, avgCount = 0;
    double average = 0;
    printf("How many numbers? "); scanf("%d", &size);
    double arr[size];
    printf("Input the array elements\n");
    
    do {
       printf("[%d] = ", idx);
       arr[idx] = getNumber();
       idx++;
    } while (idx < size);
    
    showElements(arr, size); idx = 0;
    
    do {
        if (arr[idx] > 0) {
            average += arr[idx];
            avgCount++;
        }
        idx++;
    } while (idx < size);
    
    printf("\nAverage of %d positive numbers is %.2lf", avgCount, average/=avgCount);
    
    return 0;
}