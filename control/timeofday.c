#include <stdio.h>

/*
    0-11: "Good morning"
    12-17: "Good afternoon"
    18-23: "Good evening"
    Others: "Invalid input"
*/

int main(void) {
    int hour;
    printf("Enter hour: "); scanf("%d", &hour);
    if (hour >= 0 && hour <= 11) {
        printf("Good morning");
    } else if (hour >= 12 && hour <= 17) {
        printf("Good afternoon");
    } else if (hour >= 18 && hour <= 23) {
        printf("Good evening");
    } else {
        printf("Invalid input");
    }

    return 0;
}