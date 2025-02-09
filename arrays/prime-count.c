#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

int countPrimes(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) count++;
    }
    return count;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter array values:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int primeCount = countPrimes(arr, size);
    printf("Number of prime numbers: %d\n", primeCount);
    
    return 0;
}