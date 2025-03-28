#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void pushAtEnd(Node** list, int data);
void swapData(Node* x, Node* y);
void bSort(Node** list);
void displayList(Node** list);

int main(void) {
    int size;
    Node* head = NULL;
    
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    for (int i = 0 ; i < size ; i++) {
        int data;
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        pushAtEnd(&head, data);
    }
    
    printf("Original linked list: ");
    displayList(&head);
    
    putchar('\n');
    bSort(&head);
    printf("Sorted linked list: ");
    displayList(&head);
    
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

void swapData(Node* x, Node* y) {
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

void bSort(Node** list) {
    if (*list == NULL) return;
    Node* out_trav = *list;
    
    int swapped = 1;
    while (out_trav->next != NULL && swapped) {
        swapped = 0;
        Node* in_trav = *list;
        while (in_trav->next != NULL) {
            if (in_trav->data > in_trav->next->data) {
                swapData(in_trav, in_trav->next);
                swapped = 1;
            }
            in_trav = in_trav->next;
        }
        out_trav = out_trav->next;
    }
}

void displayList(Node** list) {
    Node* trav = *list;
    if (*list == NULL) return;
    
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
}