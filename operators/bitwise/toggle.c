#include <stdio.h>


int main() {
    int number, position;

    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Enter the bit position to toggle: ");
    scanf("%d", &position);
    

    int bitmask = 1 << position;
    int new_num = number ^ bitmask;

    printf("The new number after toggling bit at position %d is: %d\n", position, new_num);
    
    return 0;
}