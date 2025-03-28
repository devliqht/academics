#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void append(Node** list, int data);
void insertAt(Node** list, int data, int pos);
void displayList(Node** list);

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
    
    printf("Original list: ");
    displayList(&list);
    putchar('\n');
    
    
    int insertData, position;
    printf("Enter data to be inserted: ");
    scanf("%d", &insertData);
    
    printf("Enter position of data to be inserted: ");
    scanf("%d", &position);
    
    insertAt(&list, insertData, position);
    printf("Updated list: ");
    displayList(&list);
    
    return 0;
}

void displayList(Node** list) {
    Node* curr = *list;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

void append(Node** list, int data) {
    Node* curr = *list;
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    
    newNode->data = data;
    
    if (*list == NULL) {
        *list = newNode;
    } else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void insertAt(Node** list, int data, int pos) {
    Node* curr = *list;
    Node* newNode = (Node*)malloc(sizeof(Node));
     if (newNode == NULL) return;
     
    newNode->data = data;
    
    if (*list == NULL) {
        *list = newNode;
        return;
    }
    
    if (pos == 0) return;
    
    if (pos == 1) {
        newNode->next = *list;
        *list = newNode;
        return;
    }
    
    int count = 0;
    
    while (curr != NULL && count < pos - 2) { // we minus two since we're using 1-n pos instead of 0 bruh
        curr = curr->next;
        count++;
    }
    
    if (curr == NULL) {
        printf("Invalid position\n");
        return;
    }
    
    newNode->next = curr->next;
    curr->next = newNode;
}