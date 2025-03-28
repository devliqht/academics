#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void pushNode(Node** list, int data);
int countNodes(Node** list);

int main(void) {
    Node* head = NULL;
    int elem = 1;
    while (elem != 0) {
        printf("Enter element (enter 0 to stop): ");
        scanf("%d", &elem);
        
        if (elem != 0) {
            pushNode(&head, elem);
        }
    }
    
    printf("Number of nodes: %d\n", countNodes(&head));
    return 0;
}

void pushNode(Node** list, int data) {
    Node* head = *list;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    
    if (*list == NULL) {
        *list = newNode;
    } else {
        newNode->next = *list;
        *list = newNode;
    }
}

int countNodes(Node** list) {
    Node* head = *list;
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}