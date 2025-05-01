#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void pushAtEnd(Node** list, int data);
void displayList(Node** list);
Node* sum(Node** l_list, Node** s_list);

int main(void) {
    int size1, size2;
    Node* list1 = NULL, *list2 = NULL;
    printf("Enter size of first linked list: ");
    scanf("%d", &size1);
    
    for (int i = 0 ; i < size1; i++) {
        int data;
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        pushAtEnd(&list1, data);
    }
    
    printf("Enter size of second linked list: ");
    scanf("%d", &size2);
    
    for (int i = 0 ; i < size2 ; i++) {
        int data;
        printf("Enter element %d: ", i+1);
        scanf("%d", &data);
        pushAtEnd(&list2, data);
    }
    
    printf("First linked list: ");
    displayList(&list1);
    
    putchar('\n');
    
    printf("Second linked list: ");
    displayList(&list2);
    
    putchar('\n');
    
    printf("Sum: ");
    Node* sumlist = sum(&list1, &list2);
    displayList(&sumlist);
    
    return 0;
}

void pushAtEnd(Node** list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return;
    
    newNode->data = data;
    if (*list == NULL) {
        *list = newNode;
    } else {
        Node* trav = *list;
        while (trav->next != NULL) {
            trav = trav->next;
        }
        trav->next = newNode;
    }
}

void displayList(Node** list) {
    if (*list == NULL) return;
    
    Node* trav = *list;
    while (trav != NULL) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
}

Node* sum(Node** l_list, Node** s_list) {
    Node* l_trav = *l_list, *s_trav = *s_list;
    Node* sum = NULL;
    
    while (l_trav != NULL || s_trav != NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) return NULL;
    
        newNode->next = NULL;
        newNode->data = 0;
        newNode->data += (l_trav != NULL) ? l_trav->data : 0;
        newNode->data += (s_trav != NULL) ? s_trav->data : 0;
        
        if (sum == NULL) {
            sum = newNode;
        } else {
            Node* trav = sum;
            while (trav->next != NULL) {
                trav = trav->next;
            }
            trav->next = newNode;
        }
        
        if (l_trav != NULL) l_trav = l_trav->next;
        if (s_trav != NULL) s_trav = s_trav->next;
    }
    
    return sum;
}