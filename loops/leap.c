#include <stdio.h>

/*
    Enter a year: 2028
    Leap years between 2028 and 2020:
    2020
    2024
    2028

    Enter a year: 2001
    Leap years between 2001 and 2020:
    2004
    2008
    2012
    2016
    2020
*/

int main(void) {
    int year, covid = 2020;
    printf("Enter a year: "); scanf("%d", &year);
    printf("Leap years between %d and %d: \n", year, covid);

    for (int i = year; i != covid; ) {
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            printf("%d\n", i);
        }
        if (i > covid) i--;
        if (i < covid) i++;
    }
    return 0;
}