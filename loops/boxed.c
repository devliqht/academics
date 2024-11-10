#include <stdio.h>

void boxDisplay(int size);
int main(void) {
    int size;
    printf("Size of the box: "); scanf("%d", &size);

    if (4 > size || size > 12) {
        printf("Invalid box size!");
        return 0;
    }
 
    printf("\n");
    boxDisplay(size);
    // 0 == 0 || j != 11
    // 0 != 1 || j != 11....
    // 0 != 11 || 11 == 11;

}

void boxDisplay(int size) {
    int ctr = size - 1;
    int i = 0;
    while (i < size) {
        for (int j = 0; j < size; j++) {
            if (i == j || j == ctr) {
                printf("0 ");

            } else {
                printf("- ");
            }
        }
        printf("\n");
        ctr--;
        i++;
    }
}