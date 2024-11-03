#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double binaryOperation(double a, double b);


int main(void) {
    double num1, num2;

    printf("Please enter 2 numbers: \n");
    scanf("%lf %lf", &num1, &num2);

    printf("A * B = [%lf]\n", binaryOperation(num1, num2));
    return 0;
}

double binaryOperation(double a, double b) {
    double val = 3.0f * (a+b);

    return val;
}