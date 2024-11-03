#include <stdio.h>
void display(float vat, float price) {
    printf("\nVAT (12%%) = %.2f\n", vat);
    printf("Total Price: %.2f", price);
}
int main(void) {
    int code = 0, gallons = 0;

    float p1 = 108.17, p2 = 3.7, p3 = 4.86, p4 = 4.96, p5 = 1.26;
    printf("Enter Product Code: "); scanf("%d", &code);
    printf("How many gallons? "); scanf("%d", &gallons);

    if (gallons < 1 || gallons > 14) {
        printf("Only a minimum of 1 and maximum of 14 gallons are allowed per transaction.");
        return 0;
    }

    float totalPrice, vat;
    switch (code) {
        case 1: 
            totalPrice = p1*gallons*(1.0f+0.12f)+23.7f;
            vat = p1 * 0.12;
 
            break;
        case 2:
            totalPrice = p2*gallons*(1.0f+0.12f)+0.19f;
            vat = p1 * 0.12;
            break;
        case 3:
            totalPrice = p3*gallons*(1.0f+0.12f)+1.1f;
            vat = p1 * 0.12;
            break;
        case 4:
            totalPrice = p4*gallons*(1.0f+0.12f)+1.3f;
            vat = p1 * 0.12;
            break;
        case 5: 
            totalPrice = p5*gallons*(1.0f+0.12f)+0.5f;
            vat = p1 * 0.12;
            break;
        default:
            printf("Invalid product code");
            return 0;
    }
    display(vat, totalPrice);
    return 0;
}