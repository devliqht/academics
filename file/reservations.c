#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024

/*
    Enter the number of reservations: 2
    Enter reservation 1 details:
    Name: John Doe
    Number of guests: 3
    Room type (Standard, Premium, Deluxe): Standard
    Enter reservation 2 details:
    Name: Ana Mae
    Number of guests: 5
    Room type (Standard, Premium, Deluxe): Deluxe
*/

int main(void) {
    char name[BUFFER_SIZE], roomType[BUFFER_SIZE];
    int guests, n;

    FILE* fp; fp = fopen("reservations.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }   

    printf("Enter the number of reservations: "); scanf("%d", &n); getchar();

    for (int i = 0; i < n; i++) {
        printf("Enter reservation %d details:\n", i+1);
        printf("Name: "); fgets(name, BUFFER_SIZE, stdin);
        name[strcspn(name, "\n")] = '\0';

        printf("Number of guests: "); scanf("%d", &guests); getchar();
        printf("Room type (Standard, Premium, Deluxe): "); fgets(roomType, BUFFER_SIZE, stdin);
        roomType[strcspn(roomType, "\n")] = '\0';

        fprintf(fp, "Name: %s\nNumber of guests: %d\nRoom type: %s\n\n", name, guests, roomType);
    }

    fclose(fp);
    return 0;
}