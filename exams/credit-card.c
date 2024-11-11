#include <stdio.h>
#include <stdlib.h>

int* getNums();
void editArray(int* arr);
char checkArray(int* arr);
void displayCard(int* arr);

int main(void) {
    printf("Please enter your credit card info: \n");
    int* card = getNums();

    editArray(card);
    displayCard(card); 

    printf("Your credit card is: %c\n", checkArray(card));
    return 0;
}

int* getNums() {
    int* arr = (int*)calloc(16, sizeof(int));
    for (int ndx = 0; ndx < 16; ndx += 4) {
        scanf("%d", &arr[ndx]);
    }
    return arr;
}
void editArray(int* arr) {
    for (int ndx = 0; ndx < 16; ndx += 4) {
        for (int jdx = 3; jdx > 0; jdx--) { // 3, 2, 1
            arr[ndx+jdx] = arr[ndx] % 10;
            arr[ndx] /= 10;
        }
    }
}
char checkArray(int* arr) {
    int sum = 0;
    for (int ndx = 0; ndx < 16; ndx += 2) { // 0, 2, 4, 6, 8, 10, 12, 14
        int ndxsum = arr[ndx] * 2;
        if (ndxsum > 9) {
                arr[ndx] = ((ndxsum / 10) + (ndxsum % 10));
        } else {
            arr[ndx] = ndxsum;
        }
    }
    for (int ndx = 0; ndx < 16; ndx++) {
        sum += arr[ndx];
    }
    if (sum % 10 == 0) {
        return 'V';
    }
    return 'I';
}

void displayCard(int* arr) {
    printf("Your credit card: ");
    for (int idx = 0; idx < 16; idx += 4) {
        for (int jdx = 0; jdx < 4; jdx++) {
            printf("%d", arr[idx+jdx]);
        }
        printf(" ");
    }
    printf("\n");
}

/*
    arr[0] = 5234       arr[0] = 5, arr[1] = 2, arr[2] = 3, arr[3] = 4
    arr[4] = 8213       arr[4] = 8, arr[5] = 2, arr[6] = 1, arr[7] = 3
    arr[8] = 3410       arr[8] = 3, arr[9] = 4, arr[10] = 1, arr[11] = 0
    arr[12] = 1298      arr[12] = 1, arr[13] = 2, arr[14] = 0, arr[15] = 8
*/