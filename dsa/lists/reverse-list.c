#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node, *LIST;

Node* createNode(int data);
void append(LIST* list, int data);
void reverseList(LIST* list);
void displayList(LIST list);

int main(void) {
    LIST list = NULL;
    int num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Enter the elements: ");
    for (int i = 0; i < num; i++) {
        int data;
        scanf("%d", &data);
        append(&list, data);
    }

    printf("Linked list before reversal: ");
    displayList(list);

    return 0;
}

Node* createNode(int data) {
    Node* node = malloc(sizeof(Node));
    if (node != NULL) {
        node->data = data;
        node->link = NULL;
        return node;
    }
    return NULL;
}

void append(LIST* list, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;

    if (*list == NULL) {
        *list = newNode;
    } else {
        LIST trav = *list;
        while (trav->link != NULL) {
            trav = trav->link;
        }
        trav->link = newNode;
    }
}

void displayList(LIST list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->link;
    }
}