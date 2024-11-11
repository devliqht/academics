#include <stdio.h>

void boxDisplay(int);

int main(void) {
    int arrSize;
    printf("Size of the box: "); scanf("%d", &arrSize);
    if (arrSize < 4 || arrSize > 12) {
        printf("\nInvalid box size!");
        return 0;
    }
    
    boxDisplay(arrSize);
    return 0;
}

void boxDisplay(int size) {
    int fin = size - 1;
    int i = 0, j = 0;
    printf("\n");
    while (i < size) {
        while (j < size) {
            if (j == i || j == fin) {
                printf("O ");
            } else {
                printf("- ");
            }
            j++;
        }
        j = 0;
        i++; fin--;
        printf("\n");
    }
}
