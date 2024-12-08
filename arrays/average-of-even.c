#include <stdio.h>

void calculateAverage(int* arr, double* avg, int* sum, int n) {
    int count = 0;
    if (n == 0) return;

    for (int i = 0; i < n; i++) {
        if (arr[i]%2 == 0) {
            *sum += arr[i];
            count++;
        }
    }
    *avg = *sum / count;
}

void display(int* arr, int n) {
    printf("List {");
    for (int i = 0; i < n; i++) {
        if (i < n-1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("}\n");
}

int main(void) {
    int size, sum = 0;
    double avg = 0;
    printf("Enter how many values: "); scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter the element %d: ", i+1); scanf("%d", &arr[i]);
    }
    display(arr, size);
    calculateAverage(arr, &avg, &sum, size);
    printf("The sum of even is %d.\n", sum);
    printf("The average of even is %.2lf.\n", avg);
}