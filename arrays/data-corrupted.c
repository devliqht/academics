#include <stdio.h>
#include <stdlib.h>

void display(int* arr, int size);
void listCleaning(int* unclean, int size);


int main(void) {
    int size;
    printf("Input how many items in the array: "); scanf("%d", &size);
    int uncleanData[size];
    printf("Input array values: "); 
    for (int i=0;i<size;i++) scanf("%d",&uncleanData[i]);
    listCleaning(uncleanData, size);
}

void display(int* arr, int size) {
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
}

void listCleaning(int* unclean, int size){
    int idx = 0, startIdx, endIdx, sum = 0, cleanedSize = 0;

    for (idx; idx < size; idx++) {
        if (unclean[idx] == -1) {
            startIdx = idx;
            for (int jdx = idx+1; jdx < size; jdx++) {
                if (unclean[jdx] == -1) {
                    endIdx = jdx;
                    break;
                }
            }
            idx = endIdx+1;
            sum += ((endIdx - startIdx) + 1);
        }
    }
    cleanedSize = size - sum;

    if (cleanedSize == 0) {
        printf("Oh no Data is fully corrupted and cannot be recovered!\n");
        return;
    }

    int* cleaned = (int*)malloc(cleanedSize*sizeof(int));
    idx = 0;
    int cleanedIdx = 0;

    for (idx; idx < size; idx++) {
        if (unclean[idx] == -1) {
            startIdx = idx;
            for (int jdx = idx+1; jdx < size; jdx++) {
                if (unclean[jdx] == -1) {
                    endIdx = jdx;
                    break;
                }
            }
            idx = endIdx+1;
            if (idx >= size) {
                break;
            }
        } 
        cleaned[cleanedIdx++] = unclean[idx];
    }
    
    printf("Data has been recovered!\nCleaned Data: ");
    display(cleaned, cleanedSize);
    puts("\n");
}