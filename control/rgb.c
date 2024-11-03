#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    MAGENTA,
    UNKNOWN
} colors;
/*
    Enter a color name (red, green, blue, yellow, or magenta): red
    RGB value: (255, 0, 0)

    For Red
        red = 255
        green = 0
        blue = 0
    For Green
        red = 0
        green = 255
        blue = 0
    For Blue
        red = 0
        green = 0
        blue = 255
    For Yellow
        red = 255
        green = 255
        blue = 0
    For Magenta
        red = 202
        green = 31
        blue = 123

*/

void strlower(char* str){ 
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

void printRGB(int r, int g, int b) {
    printf("RGB Value: (%d, %d, %d)", r, g, b);
}

int main(void) {
    char option[MAX];
    colors color;

    printf("Enter a color name (red, green, blue, yellow, or magenta): "); fgets(option, MAX, stdin); 
    option[strcspn(option, "\n")] = '\0';
    strlower(option);

    if (strcmp(option, "red") == 0) color = RED;
    if (strcmp(option, "green") == 0) color = GREEN;
    if (strcmp(option, "blue") == 0) color = BLUE;
    if (strcmp(option, "yellow") == 0) color = YELLOW;
    if (strcmp(option, "magenta") == 0) color = MAGENTA;

    switch (color) {
        case RED:
            printRGB(255, 0, 0);
            break;
        case GREEN:
            printRGB(0, 255, 0);
            break;
        case BLUE:
            printRGB(0, 0, 255);
            break;
        case YELLOW:
            printRGB(255, 255, 0);
            break;
        case MAGENTA:
            printRGB(202, 31, 123);
            break;
        default:
            printf("Invalid color name.\n");
            return 1;
    }

    return 0;
}