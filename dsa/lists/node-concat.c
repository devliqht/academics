#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** list, int data);
Node* connect(Node** first, Node** second);
void printList(Node** list);

int main(void) {
    Node* firstList = NULL, *secondList = NULL;
    
    int firstSize = 0, secondSize = 0;
    printf("Enter size of linked list 1: ");
    scanf("%d", &firstSize);
    for (int i = 0; i < firstSize; i++) {
        int data;
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        append(&firstList, data);
    }
    
    printf("Enter size of linked list 2: ");
    scanf("%d", &secondSize);
    for (int i = 0; i < secondSize; i++) {
        int data;
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        append(&secondList, data);
    }
    
    printf("Linked list 1: ");
    printList(&firstList);
    putchar('\n');
    printf("Linked list 2: ");
    printList(&secondList);
    
    putchar('\n');
    printf("Concatenated linked list: ");
    Node* concatList = connect(&firstList, &secondList);
    printList(&concatList);
    
    return 0;
}

void append(Node** list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    newNode->data = data;
    
    if (*list == NULL) {
        *list = newNode;
    } else {
        Node* curr = *list;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

Node* connect(Node** first, Node** second) {
    if (*first == NULL) return *second;
    if (*second == NULL) return *first;
    
    Node* curr = *first;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = *second;
    
    return *first;
}

void printList(Node** list) {
    Node* curr = *list;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}