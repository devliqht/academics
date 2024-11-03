#include <stdio.h>
#include <math.h>
#define PI 3.14

int main(void) {
    double radius, height, volume;
    printf("Enter radius: "); scanf("%lf", &radius);
    printf("Enter height: "); scanf("%lf", &height);

    volume = PI*(pow(radius, 2))*height;
    printf("Volume = %.2f", volume);

    return 0;
}