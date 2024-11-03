/*
Create a program that finds the least amount of coins for change
Recreate the output by using 4 functions for each coin
and finally call it with one other function which prints the below

Sample Output
Change: 27
Coin:
Peso   - 2
Singko - 1
Dyes   - 0
Bente  - 1
*/

#include <stdio.h>

int CountPeso(int);
int CountSingko(int);
int CountDyes(int);
int CountBente(int);
void Coin(int);

int main() {
    int x=0;
    printf("Change: ");
    scanf("%d",&x);
    
    Coin(x);
    return 0;
}


int CountPeso(int amnt){
    //Return the amount of piso coins as change.
    int change = amnt%5;
    return change;
}

int CountSingko(int amnt){
    //Return the amount of 5 peso coins as change.
    int change = (amnt%10)/5;
    return change;
}

int CountDyes(int amnt){
    //Return the amount of 10 peso coins as change.
    int change = (amnt%20)/10;
    return change;
}

int CountBente(int amnt){
    //Return the amount of 20 peso as change.
    int change = amnt/20;
    return change;
}

void Coin(int x){
    printf("Coin:");
    printf("\nPeso   - %d",CountPeso(x));
    printf("\nSingko - %d",CountSingko(x));
    printf("\nDyes   - %d",CountDyes(x));
    printf("\nBente  - %d",CountBente(x));
}