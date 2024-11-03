#include<stdio.h>
int decimal;
void decimalToBinary(int decimal);
void decimalToOctal(int decimal);
void decimalToHexadecimal(int decimal);


int main(){
    printf("Enter the decimal: ");
    scanf("%d", &decimal);
    printf("\nBinary: ");
    decimalToBinary(decimal);
    printf("\nOctal: ");
    decimalToOctal(decimal);
    printf("\nHexaDecimal: ");
    decimalToHexadecimal(decimal);
}

void decimalToBinary(int decimal){
    if(decimal > 1)
    decimalToBinary(decimal / 2);
    printf("%d", decimal % 2);
}

void decimalToOctal(int decimal){
    if(decimal > 1)
    decimalToOctal(decimal / 8);
    printf("%d", decimal % 8);
}

void decimalToHexadecimal(int decimal) {
    int remainder;
    char hex[100];
    int i = 0;
    
    if (decimal == 0) {
        printf("0");
        return;
    }
    
    while (decimal > 0) {
        remainder = decimal % 16;
        decimal = decimal / 16;
        
        if (remainder < 10) {
            hex[i] = remainder + '0';  
        } else {
            hex[i] = remainder - 10 + 'A';
        }
        i++;
    }
    
    
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}