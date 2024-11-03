#include <stdio.h>

int main(void) {
    double temp;

    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &temp);

    if (temp > 37) {
        printf("Warning: The temperature is above normal human body temperature");
    } else if (temp < 0) {
        printf("The temperature is below freezing");
    } else if (temp > 0 && temp <= 37) {
        printf("The temperature is within a safe range");
    } else {
        printf("The temperature is at freezing point.");
    }

    return 0;
}