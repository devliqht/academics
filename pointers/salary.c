#include <stdio.h>

int main(void) {
    double salary, *salaryPtr = &salary;
    printf("Enter salary: "); scanf("%lf", &salary);
    printf("Your salary is: %.2lf\n", *salaryPtr);
    printf("Your salary after doubling is: %.2lf", *salaryPtr*2.0f);

    return 0;
}