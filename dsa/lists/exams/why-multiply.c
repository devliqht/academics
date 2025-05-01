#include <stdio.h>
#include <stdlib.h>

typedef struct ntype {
    int data;
    struct ntype* link;
} ntype, *LIST;

void append(LIST* list, int data);
void display(LIST list);
void multiply(LIST* list);

int main(void) {
    LIST head = NULL;
    int num;
    printf("Enter the number of nodes: ");
    scanf("%d", &num);
    printf("Enter the values for the nodes:\n");
    int data;
    for (int i = 0; i < num; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Original list:\n");
    display(head);
    printf("Modified list:\n");
    multiply(&head);
    display(head);

    return 0;
}

void append(LIST* list, int data) {
    ntype* temp = (ntype*)malloc(sizeof(ntype));
    if (temp != NULL) {
        temp->data = data;
        temp->link = NULL;
        if (*list == NULL) {
            *list = temp;
        } else {
            LIST trav = *list;
            while (trav->link != NULL) trav = trav->link;
            trav->link = temp;
        }
    }
}

void display(LIST list) {
    while (list != NULL) {
        printf("%d -> ", list->data);
        list = list->link;
    }
    printf("NULL\n");
}

void multiply(LIST* list) {
    LIST trav = *list;
    while (trav != NULL) {
        ntype* temp = (ntype*)malloc(sizeof(ntype));
        if (temp != NULL) {
            if (trav->data % 2 == 0) {
                temp->data = trav->data * 2;
            } else {
                temp->data = trav->data + 1;
            }
        }
        temp->link = trav->link; 
        trav->link = temp;
        trav = temp->link;
    }
}