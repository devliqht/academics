#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Mark done price for bulk orders.
    A set contains 5 trays of 2.5 dozen per tray.
    Orders that reach atleast a set will have a discount of 5%.
    Orders for more than 2 sets will have 10% discount;

*/
const int set = 150;
const int dozen = 12;
const float egg16 = 15.00;
const float egg18 = 22.50;
const float penoy = 13.00;

void displayShop();
void displaySummary(int eggType, int eggOrders, int amount);

int main(void) {
    int eggType, eggOrders, amount;
    const float set = 150;
    const int dozen = 12;


    displayShop();
        do {
            printf("Enter your egg type: ");
            scanf("%d", &eggType);
        } while (eggType < 1 || eggType > 3);
        
    printf("Enter total egg orders: ");
    scanf("%d", &eggOrders);
    printf("Enter amount: ");
    scanf("%d", &amount);

    puts("\n");

    displaySummary(eggType, eggOrders, amount);

    return 0;
}

void displayShop() {
    printf("Itlog ni Noy AKIL!\n");
    printf("[1] #16 @ Php 15.00\n");
    printf("[2] #18 @ Php 22.50\n");
    printf("[3] penoy @ Php 13.00\n");
}

void displaySummary(int eggType, int eggOrders, int amount) {

    float totalCost, orders = eggOrders, amt = amount;
    if(eggType == 1) {
        totalCost = egg16 * orders;
    } else if (eggType == 2) {
        totalCost = egg18 * orders;
    } else if (eggType == 3) {
        totalCost = penoy * orders;
    }

    float disc1 = totalCost * 0.05;
    float disc2 = totalCost * 0.10;

    float discPrice1 = totalCost - disc1;
    float discPrice2 = totalCost - disc2;

    printf("SUMMARY\n");
    printf("Total Cost: Php %.2f\n", totalCost);
    
    if (orders >= set*1.0f && orders <= set*2.0f) {
        printf("Discount: Php %.2f\n", disc1);
        printf("Discounted Price: Php %.2f\n", discPrice1);
        float change = amt - discPrice1;
        if (change < 0) {
        printf("Change: (%.2f)", sqrt(pow(change,2)));
        } else {
            printf("Change: %.2f", change);
        }

    } else if (orders >= set*1.0f && orders >= set*2.0f) {
        printf("Discount: Php %.2f\n", disc2);
        printf("Discount Price: Php %.2f\n", discPrice2);
        float change = amt - discPrice2;
        if (change < 0) {
        printf("Change: (%.2f)", sqrt(pow(change,2)));
        } else {
            printf("Change: %.2f", change);
        }
    } else {
        float change = amt - totalCost;
        printf("Discount: Php %.2f\n", 0.0f);
        if (change < 0) {
        printf("Change: (%.2f)", sqrt(pow(change,2)));
        } else {
            printf("Change: %.2f", change);
        }
    }

    


    

}