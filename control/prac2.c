#include <stdio.h>
#include <ctype.h>

int main(void) {
    char option;
    printf("Enter option: "); scanf("%c", &option);

    char choice = tolower(option);

    switch (choice) {
        case 'a':
            printf("You selected option A.");
            break;
        case 'b':
            printf("You selected option B.");
            break;
        case 'c':
            printf("You selected option C.");
            break;
        case 'q':
            printf("Exiting the program.");
            break;
        default:
            printf("Invalid option.");
            break;
    }
}