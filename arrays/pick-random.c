#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int lower = 6750;
    int upper = 7250;
    int whole_number = lower + rand() % (upper - lower + 1);
    float decimals[] = {0, 25, 50, 75};
    float centavos = decimals[rand() % 4]; 

    float random_amount = whole_number + centavos / 100.0;

    printf("chase cokaliong: %.2f\n", random_amount);

    return 0;
}