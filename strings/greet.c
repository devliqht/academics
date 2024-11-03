#include <stdio.h>

void greet(char*);
void generateGreeting() {
    char name[100];
    printf("Enter your name: "); gets(name);
    greet(name);
}


int main(void) {
    generateGreeting();
    return 0;
}

void greet(char* name) {
    printf("Hello, %s!", name);
}