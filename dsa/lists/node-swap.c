#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** list, int data);
void swapNode(Node* first, Node* second);
void swapDataList(Node** list);
void printList(Node** list);

int main(void) {
    Node* list = NULL;
    int size;
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        int data;
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        append(&list, data);
    }
    printf("Original linked list: ");
    printList(&list);
    
    swapDataList(&list);
    putchar('\n');
    printf("Updated linked list: ");
    printList(&list);
    
}

void append(Node** list, int data) {
    Node* curr = *list;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (newNode == NULL) return;
    
    if (*list == NULL) {
        *list = newNode;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void swapNode(Node* first, Node* second) {
    int tempData = first->data;
    first->data = second->data;
    second->data = tempData;
}

void swapDataList(Node** list) {
    if (*list == NULL || (*list)->next == NULL) return; // Empty or single-node case

    Node dummy;
    dummy.next = *list;
    Node* prev = &dummy;
    Node* curr = *list;
    
    while (curr != NULL && curr->next != NULL) {
        Node* next = curr->next;

        // Swap the nodes
        prev->next = next;
        curr->next = next->next;
        next->next = curr;

        // Move forward
        prev = curr;
        curr = curr->next;
        
        // dummy -> 2 
        // 
        // 
    }

    *list = dummy.next; // Update head in case it changed
}

void printList(Node** list) {
    Node* curr = *list;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}