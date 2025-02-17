#include <stdio.h>
#include <stdlib.h>

void resizeArr(int* arr, int newSize);
int* findIntersection(int* arr1, int* arr2, int size1, int size2, int* sizePtr);
int getInput(const char* input);
int* getArrayInput(const char* input, int size);

int main(void) {
    int s1 = getInput("Enter size of first array: ");
    int s2 = getInput("Enter size of second array: ");
    int intersectionSize;
    
    int* arr1 = getArrayInput("Enter elements of first array: ", s1);
    int* arr2 = getArrayInput("Enter elements of second array: ", s2);
    
    int* result = findIntersection(arr1, arr2, s1, s2, &intersectionSize);
    printf("Intersection of the two arrays: ");
    for (int i = 0; i < intersectionSize; i++) printf("%d ", *(result+i));
    
    free(arr1); free(arr2); free(result);
    
    return 0;
    
}

void resizeArr(int* arr, int newSize) {
    int* newArr = (int*)calloc(newSize, sizeof(int));
    
    if (newArr == NULL) {
        printf("Memory allocation failed. \n");
        return;
    }
    
    for (int i = 0; i < newSize; i++) {
        *(newArr+i) = *(arr+i);
    } 
    
    arr = newArr;
}

int* findIntersection(int* arr1, int* arr2, int size1, int size2, int* sizePtr) {
    int* result = (int*)malloc(1 * sizeof(int));
    int idx = 0;
    
    if (result == NULL) {
        printf("Memory allocation failed. \n");
        return NULL;
    }
    
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (*(arr1+i) == *(arr2+j)) {
                *(result+idx++) = *(arr1+i);
                resizeArr(result, idx+1);
            }
        }
    }
    
    *sizePtr = idx;
    return result;
}

int getInput(const char* input) {
    printf("%s", input);
    int n; 
    scanf("%d", &n);
    
    return n;
}

int* getArrayInput(const char* input, int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    
    if (arr == NULL) {
        printf("Memory allocation failed. \n");
        return NULL;
    }
    
    printf("%s", input);
    for (int i = 0; i < size; i++) {
        scanf("%d", arr+i);
    }
    
    return arr;
}