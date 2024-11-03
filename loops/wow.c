#include <stdio.h>
#include <math.h>

int main() {
    double num;

    printf("Enter a number: "); scanf("%lf", &num);
    double answer = pow(((num * 4.0f) - 15.0f), 3.0f) / 5.0f;
    double backwards = (cbrt((answer * 5)) + 15) / 4;

    printf("Original: %.2lf\n", num);
    printf("Result: %.2lf\n", answer);
    printf("Work backwards (should be original): %.2lf\n", backwards);
}