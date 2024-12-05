#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *arr;
    int count;
} arrStruct;

typedef struct{
    arrStruct originalArray;
    arrStruct harshadArray;
    arrStruct palindromeArray;
} multiArrayRecords;

void moveHarshadAndPalindrome(multiArrayRecords*);
void setSize(multiArrayRecords*);
int isHarshad(int num);
int isPalindrome(int num);
void populateArray(int*, int);

int main() {
    int size;
    printf("Input Size of Array: "); scanf("%d", &size);
    int arr[size];
    
    multiArrayRecords record;
    record.originalArray.arr = arr;
    record.originalArray.count = size;
    
    printf("Populate the Array: "); populateArray(record.originalArray.arr, size);
    
    setSize(&record);
    int harshadArr[record.harshadArray.count], palindromeArr[record.palindromeArray.count];
    
    record.harshadArray.arr = harshadArr;
    record.palindromeArray.arr = palindromeArr;
    
    moveHarshadAndPalindrome(&record);

    printf("\nHarshad numbers: "); 
    for (int i = 0; i < record.harshadArray.count; i++) {
        printf("%d ", record.harshadArray.arr[i]);
    }
    
    printf("\n\nPalindrome numbers: "); 
    for (int i = 0; i < record.palindromeArray.count; i++) {
        printf("%d ", record.palindromeArray.arr[i]);
    }
    return 0;
}
void moveHarshadAndPalindrome(multiArrayRecords* record) {
    int arrSize = record->originalArray.count;
    int h = 0, p = 0;
    for (int i = 0; i < arrSize; i++) {
        if (isHarshad(record->originalArray.arr[i])) {
            record->harshadArray.arr[h] = record->originalArray.arr[i];
            h++;
        }
        if (isPalindrome(record->originalArray.arr[i])) {
            record->palindromeArray.arr[p] = record->originalArray.arr[i];
            p++;
        }
    }
    
}

void setSize(multiArrayRecords* record) {
    int harshSize = 0, palindromeSize = 0, arrSize = record->originalArray.count;
    
    for (int i = 0; i < arrSize; i++) {
        if (isHarshad(record->originalArray.arr[i])) {
            harshSize++;
        }
        if (isPalindrome(record->originalArray.arr[i])) {
            palindromeSize++;
        }
    }
    
    record->harshadArray.count = harshSize;
    record->palindromeArray.count = palindromeSize;
}

int isHarshad(int num) {
    int sum = 0, temp = num;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    return (num % sum == 0);
}

int isPalindrome(int num) {
    int rev = 0, temp = num;
    while (temp > 0) {
        rev = (rev * 10) + (temp % 10);
        temp /= 10;
    }
    return (num == rev);
}

void populateArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}