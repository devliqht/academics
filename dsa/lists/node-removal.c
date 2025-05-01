#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void displayList(Node** list);
void pushAtEnd(Node** list, int data);
void deleteByPos(Node** list, int pos);

int main(void) {
    int size;
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    
    Node* list = NULL;
    for (int i = 0 ; i < size ; i++) {
        int data;
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        pushAtEnd(&list, data);
    }
    
    printf("Original list: ");
    displayList(&list);
    putchar('\n');
    
    printf("Enter position of data to be removed: ");
    int pos;
    scanf("%d", &pos);
    
    deleteByPos(&list, pos);
    printf("Updated list: ");
    displayList(&list);
    
    return 0;
}

void displayList(Node** list) {
    Node* trav = *list;
    if (*list == NULL) return;
    
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
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

void deleteByPos(Node** list, int pos) {
    Node* trav = *list, *prev = NULL;
    if (*list == NULL) return;
    
    if (pos <= 0) return; // since we're using 1-n pos...
    
    if (pos == 1) {
        Node* temp = *list;
        *list = temp->next;
        free(temp);
        return;
    }
    
    int count = 0;
    while (trav != NULL && count < pos - 1) {
        prev = trav;
        trav = trav->next;
        count++;
    }
    
    if (trav == NULL) {
        printf("Invalid position\n");
        return;
    }
    
    prev->next = trav->next;
    free(trav);
}