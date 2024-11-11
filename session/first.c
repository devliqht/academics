#include <stdio.h>

int main(void) {
    float subjects[5], average = 0;
    for (int i = 0; i < 5; i++) {
        printf("Enter the marks of subject %d: ", i + 1);
        scanf("%f", &subjects[i]);
        average += subjects[i];
    }
    printf("The marks of the subjects are: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", subjects[i]);
    }
    printf("\nAverage marks: %.2f", average/=5.0f);
    return 0;
}