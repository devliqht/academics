#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void pushAtEnd(Node** list, int data);
int searchFor(Node** list, int elem);

int main(void) {
    Node* head = NULL;
    int size;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    
    printf("Enter the elements of the array: ");
    for (int i = 0 ; i < size ; i++) {
        int data;
        scanf("%d", &data);
        pushAtEnd(&head, data);
    }
    
    printf("Enter the element to search for: ");
    int choice;
    scanf("%d", &choice);
    
    (searchFor(&head, choice)) ? printf("Element found in the array") : printf("Element not found in the array");
    
    
    return 0;
}

void pushAtEnd(Node** list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = data;
    Node* trav = *list;
    
    if (*list == NULL) {
        *list = newNode;
    } else {
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
}

int searchFor(Node** list, int elem) {
    Node* trav = *list;
    if (*list == NULL) return 0;
    while (trav != NULL) {
        if (trav->data == elem) return 1;
        trav = trav->next;
    }
    if (trav == NULL) return 0;
}