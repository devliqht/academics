#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void displayList(Node** list);
void insertFirst(Node** list, int data);
int checkIfPalindrome(Node** list);

int main(void) {
    Node* list = NULL;
    
    int size;
    printf("Enter size of linked list: ");
    scanf("%d", &size);
    
    for (int i = 0 ; i < size ; i++) {
        int data;
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        insertFirst(&list, data);
    }
    
    printf("Original list: ");
    displayList(&list);
    putchar('\n');
    
    (checkIfPalindrome(&list)) ? printf("The linked list is a palindrome.") : printf("The linked list is not a palindrome.");
    
    return 0; 
}

void displayList(Node** list) {
    Node* trav = *list;
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
}

void insertFirst(Node** list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    
    newNode->data = data;
    
    if (*list == NULL) {
        *list = newNode;
    } else {
        newNode->next = *list;
        *list = newNode;
    }
}

int checkIfPalindrome(Node** list) {
    if (*list == NULL) return 0;
    
    Node* trav = *list;
    int size = 0;
    while (trav->next != NULL) {
        size++;
        trav = trav->next;
    }
    
    int count = 0;
    Node* head = *list;
    while (head->next != NULL && count < size) {
        Node* end = *list;
        for (int i = 0; i < size; i++) {
            end = end->next;
        }
 
        if (head->data != end->data) return 0;
        head = head->next;
        size--;
        count++;
    }
    return 1;
}
