#include <stdio.h>
#include <stdlib.h>

// Create a program that asks for user input for the size of your linked list. Afterwards, populate that linked list with values, 
// and filter it into a new Node called cleanedList which contains the values that are not enclosed by -1. 
// If data has been cleaned, display Data has been recovered! Otherwise, display “Oh no Data is fully corrupted and cannot be recovered!” 
// then terminate the program.

typedef struct Node {
    int data;
    struct Node* link;
} Node;

Node* listCleaning(Node* list);
void getInput(Node** list);
void display(Node* list);

int main(void) {
    Node* list = NULL;
    int n;
    printf("Input how many items you want in the linked list: ");
    scanf("%d", &n);
    printf("Enter linked list values: ");
    for (int i = 0 ; i < n ; i++) {
        getInput(&list);
    }

    Node* cleaned = listCleaning(list);
    printf("Cleaned data: ");
    display(cleaned);

    return 0;
}

Node* listCleaning(Node* list) {
    Node* cleaned = NULL;
    Node* cleanedCurr = NULL;
    Node* curr = list;
    int isValid = 0;
    int count = 0;

    while (curr != NULL) {
        if (curr->data == -1) {
            Node* trav = curr;
            do {   
                trav = trav->link;
                count++;
            } while (trav != NULL && trav->data != -1);
            if (curr == list && trav->link == NULL) {
                printf("Oh no Data is fully corrupted and cannot be recovered!\n");
                exit(0); 
            }    
            curr = trav->link;
        }

        if (curr != NULL) {
            Node* temp = malloc(sizeof(Node));
            temp->data = curr->data;
            temp->link = NULL;
            if (cleaned == NULL) {
                cleaned = temp;
                cleanedCurr = temp;
            } else {
                cleanedCurr->link = temp;
                cleanedCurr = temp;
            }
            curr = curr->link;
        }
    }


    printf("Data has been recovered!\n");
    return cleaned;

}

void getInput(Node** list) {
    int data;
    scanf("%d", &data);

    Node* temp = malloc(sizeof(Node));
    if (temp != NULL) {
        temp->data = data;
        temp->link = NULL;
        if (*list == NULL) {
            *list = temp;
        } else {
            Node* trav = *list;
            while (trav->link != NULL) {
                trav = trav->link;
            }
            trav->link = temp;
        }
    }
}

void display(Node* list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->link;
    }
}
