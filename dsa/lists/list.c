#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

int main(void) {
    Node* head = NULL;
    head = createNode(45);
    Node* element = createNode(78);
    head->next = element;
    printf("element->Data: %d", element->data);
    printf("\nhead->next->data: %d", head->next->data);

    return 0;
}
