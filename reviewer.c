#include <stdio.h> 

int global = 10;

int testFunc();

int main(void) { 
    printf("main: %d", global); // Yey, it works!
    testFunc();
    return 0;
}

int testFunc() {
    printf("\ntestFunc: %d", global); // Yey, this function can access it too!
}

