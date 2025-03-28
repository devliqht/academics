#include <stdio.h>
#include <string.h>

struct Sensor {
    int value;
};

struct Student {
    char name[50];
    int age;
} X;

struct Sensor sensors[4] = {{55}, {67}, {72}, {89}};

int main(void) {
    char str1[20] = "Good Luck";
    char str2[20] = "Good";

    (strcmp(str1, str2) == 0) ? printf("wow") : printf("not wow");

    int val1 = sensors[0].value;
    int val2 = (*((sensors))).value;
    
    printf("\nval1 %d val2 %d", val1, val2);

    struct Student *ptr = &X;
    strcpy(ptr->name,"Kytleen Marie");
    printf("\nstring: %s", ptr->name);

}