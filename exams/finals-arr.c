#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void initialize(int arr[], int* count);
void display(int arr[], int count);
int searchElem(int arr[], int count, int elem);
int insertLast(int arr[], int* count, int elem);
int insertFirst(int arr[], int* count, int elem);
int insertAtPos(int arr[], int* count, int elem, int pos);
int removeLast(int arr[], int* count);
int removeFirst(int arr[], int* count);
int removeAtPos(int arr[], int* count, int pos);
int removeElem(int arr[], int* count, int elem);
int getRange(int arr[], int count);
int* getEven(int arr[], int count);
int isSortedAscending(int arr[], int count);
void moveSmallestToFirst(int arr[], int count);
void sortArray(int arr[], int count);

int main(void) {
    int sample[MAX] = { 1, 2, 3, 4, 5 };
    display(sample, 5);

    int sample2[MAX], count, *countPtr = &count;
    initialize(sample2, countPtr);
    display(sample2, *countPtr);

    puts("\n");

    int elemFind[MAX] = { 2, 3, 4, 5, 6 };
    int elem = 5, elem2 = 7, elemCount = 5;
    int ret1 = searchElem(elemFind, elemCount, elem);
    int ret2 = searchElem(elemFind, elemCount, elem2);

    puts("----------------------------");

    printf("Element to search: %d\tReturn Value: %d\n", elem, ret1);
    printf("Element to search: %d\tReturn Value: %d\n", elem2, ret2);

    int insertSample[MAX] = { 2, 3, 4 };
    int insertCount = 3, insElem = 10, *insCountPtr = &insertCount;

    puts("----------------------------");

    printf("insertElement: %d\n", insElem);
    int insertResult = insertLast(insertSample, insCountPtr, insElem);
    printf("insertResult: %d\n", insertResult);
    display(insertSample, *insCountPtr);
    printf("\ninsertCount: %d\n", insertCount);

    puts("----------------------------");

    int insElemFirst = 20;
    printf("insElemFirst: %d\n", insElemFirst);
    int insFirstResult = insertFirst(insertSample, insCountPtr, insElemFirst);
    printf("insFirstResult: %d\n", insFirstResult);
    display(insertSample, *insCountPtr);
    printf("\ninsertCount: %d\n", insertCount);

    puts("----------------------------");

    int insElemPos = 30, pos = 3;
    printf("insElemPos: %d\n", insElemPos);
    int insPosResult = insertAtPos(insertSample, insCountPtr, insElemPos, pos);
    printf("insPosResult: %d\n", insPosResult);
    display(insertSample, *insCountPtr);
    printf("\ninsertCount: %d\n", insertCount);

    puts("----------------------------");

    int remLastResult = removeLast(insertSample, insCountPtr);
    printf("remLastResult: %d\n", remLastResult);
    display(insertSample, *insCountPtr);
    printf("\ncount: %d\n", insertCount);

    puts("----------------------------");

    int remFirstResult = removeFirst(insertSample, insCountPtr);
    printf("remFirstResult: %d\n", remFirstResult);
    display(insertSample, *insCountPtr);
    printf("\ncount: %d\n", insertCount);

    puts("----------------------------");

    int remPos = 2;
    int remPosResult = removeAtPos(insertSample, insCountPtr, remPos);
    printf("pos: %d\n", remPos);
    printf("remPosResult: %d\n", remPosResult);
    display(insertSample, *insCountPtr);
    printf("\ncount: %d\n", insertCount);

    puts("----------------------------");

    int sampleElem = 30, remCount = 4, *remCountPtr = &remCount;
    int remSample[MAX] = { 2, 3, 30, 4 };
    display(remSample, *remCountPtr); puts("\n");
    int remElemResult = removeElem(remSample, remCountPtr, sampleElem);
    printf("sampleElem: %d\n", sampleElem);
    printf("remElemResult: %d\n", remElemResult);
    display(remSample, *remCountPtr);
    printf("\ncount: %d\n", remCount);

    puts("----------------------------");

    display(remSample, remCount); puts("\n");
    int remRangeResult = getRange(remSample, *remCountPtr);
    printf("\nremRangeResult: %d\n", remRangeResult);

    puts("----------------------------");

    int* evenArr = getEven(remSample, *remCountPtr);
    for (int i = 0; i < 3; i++) {
        printf("%d ", evenArr[i]);
    }

    puts("\n----------------------------");

    int isSorted = isSortedAscending(remSample, *remCountPtr);
    display(remSample, *remCountPtr);
    printf("\nisSortedAscending: %d\n", isSorted);

    puts("----------------------------");

    int sortSample[MAX] = { 5, 10, 30, 4, 2, 20 };
    int sortSampleCount = 6, *sortCountPtr = &sortSampleCount;
    display(sortSample, *sortCountPtr);
    moveSmallestToFirst(sortSample, *sortCountPtr); puts("\n");
    display(sortSample, *sortCountPtr);

    puts("\n----------------------------");

    display(sortSample, *sortCountPtr); puts("\n");
    sortArray(sortSample, *sortCountPtr); 
    display(sortSample, *sortCountPtr);

    return 0;
}

void initialize(int arr[], int* count) {
    for (int i = 0; i < MAX; i++) {
        arr[i] = 0;
    }
    *count = 0;
}

void display(int arr[], int count) {
    if (count == 0) {
        printf("\nList is empty");
    } else if (count != 0) {
        for (int i = 0; i < count; i++) {
                printf("%d ", arr[i]);
        }
    }
}

int searchElem(int arr[], int count, int elem) {
    for (int i = 0; i < MAX; i++) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return -1;
}

int insertLast(int arr[], int* count, int elem) {
    for (int i = 0; i < *count; i++) {
        if (searchElem(arr, i, elem) != -1) {
            printf("Element already exists\n");
            return 0;
        }
    }
    if (*count < 10 && *count > 0) {
        arr[*count] = elem;
        *count += 1;
        return 1;
    }
    printf("List is full\n");
    return 0;
}

int insertFirst(int arr[], int* count, int elem) {
    for (int i = 0; i < *count; i++) {
        if (searchElem(arr, i, elem) != -1) {
            printf("Element already exists\n");
            return 0;
        }
    }

    if (*count < 10) {
        for (int i = *count - 1; i >= 0; i--) { // 3, 2, 1, 0
            arr[i+1] = arr[i]; // arr[4] = arr[3], arr[3] = arr[2], ...
        }
        arr[0] = elem;
        *count += 1;
        return 1;
    }

    printf("List is full \n");
    return 0;
}

int insertAtPos(int arr[], int* count, int elem, int pos) {
    for (int i = 0; i < *count; i++) {
        if (searchElem(arr, i, elem) != -1) {
            printf("Element already exists\n");
            return 0;
        }
    }  
    if (*count < pos) {
        printf("Invalid position\n");
        return 0;
    }
    if (pos < *count || pos >= 0) {
        for (int i = *count - 1; i >= pos; i--) { // 4, 3
            arr[i+1] = arr[i]; // arr[5] = arr[4], arr[4] = arr[3], ...
        }
        arr[pos] = elem;
        *count += 1;
        return 1;
    }
    printf("List is full");
    return 0;
}

int removeLast(int arr[], int* count) {
    if (*count > 0) {
        arr[*count-1] = 0;
        *count -= 1;
        return 1;
    }
    printf("List is empty");
    return 0;
}

int removeFirst(int arr[], int* count) {
    if (*count > 0) {
        for (int i = 0; i < *count - 1; i++) {
            arr[i] = arr[i+1];
        }
        *count -= 1;
        return 1;
    }
    printf("List is empty");
    return 0;
}

int removeAtPos(int arr[], int* count, int pos) {
    if (*count == 0) {
        printf("List is empty");
        return 0;
    }
    if (pos <= *count) {
        for (int i = pos; i <= *count - 1; i++) { // pos=1, 1 <= 4-1 : 1, 2, 3
            arr[i] = arr[i+1];
        }
        *count -= 1;
        return 1;
    }
    printf("Invalid position\n");
    return 0;
}

int removeElem(int arr[], int* count, int elem) {
    if (*count == 0) {
        printf("List is empty");
        return 0;
    } 
    for (int i = 0; i < *count; i++) {
        if (arr[i] == elem) {
            arr[i] = 0;
            for (int j = i; j <= *count - 1; j++) { // same logic as last time
                arr[j] = arr[j+1];
            }
            *count -= 1;
            return 1;
        }
    }
    printf("Element does not exist\n");
    return 0;
}

int getRange(int arr[], int count) {
    if (count == 0) {
        return 0;
    }

    int max = arr[0], min = arr[0], range;

    for (int i = 1; i < count; i++) { // 1, 2
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    printf("max: %d\n", max);

    for (int i = 0; i < count; i++) {
        if (arr[i] < min) {
            min = arr[i];
 
        }
    }

    printf("min: %d\n", min);

    range = max - min;
    return range;
}

int* getEven(int arr[], int count) {
    int evenCount = 0, idx = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        }
    }
    printf("evenCount: %d\n", evenCount);
    int* retArr = (int*)malloc((evenCount+1) * sizeof(int)); // 2, 4, -1
    for (int i = 0; i < count; i++) {
        if (arr[i] % 2 == 0) {
            retArr[idx] = arr[i];
            idx++;
        }
    }
    retArr[evenCount] = -1;
    return retArr;
}

int isSortedAscending(int arr[], int count) {
    if (count == 0) {
        return 0;
    }
    for (int i = 0; i < count - 1; i++) { // 0, 1
        if (arr[i] > arr[i+1]) { // arr[0] > arr[1], arr[1] > arr[2]
            return 0;
        }
    }
    return 1;
}

void moveSmallestToFirst(int arr[], int count) {
    int min = arr[0], ndxmin;
    for (int i = 0; i < count; i++) {
        if (arr[i] <= min) { 
            min = arr[i];
            ndxmin = i;
        }
    }
    int tmp = arr[0];
    arr[0] = min;
    arr[ndxmin] = tmp;
}

void sortArray(int arr[], int count) {
    for (int ndx = 0; ndx < count-1; ndx++) {
        moveSmallestToFirst(arr+ndx, count-ndx);
    }
}