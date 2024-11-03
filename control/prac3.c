#include <stdio.h>

int main() {
    char opt;
    double num1, num2;

    printf("Enter an operator (+, -, *, /): "); scanf("%c", &opt);
    printf("Enter two numbers: "); scanf("%lf %lf", &num1, &num2);

    switch (opt) {
        case '+':
            printf("%.2lf + %.2lf = %.2lf", num1, num2, num1+num2);
            break;
        case '-':
            printf("%.2lf - %.2lf = %.2lf", num1, num2, num1-num2);
            break;
        case '*':
            printf("%.2lf * %.2lf = %.2lf", num1, num2, num1*num2);
            break;
        case '/':
            if (num1 == 0 || num2 == 0) {
                printf("Error! Division by zero is not allowed.");
                break;
            }
            printf("%.2lf / %.2lf = %.2lf", num1, num2, num1/num2);
            break;
        default:
            printf("Error! Operator is not correct.");
            break;
    }

    return 0;
}