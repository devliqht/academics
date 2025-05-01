#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node, *LIST;

void append(LIST* list, int data);
void displayList(LIST list);

int main(void) {
    LIST list = NULL;
    append(&list, 1);
    append(&list, 2);
    displayList(list);
    append(&list, 2);
    append(&list, 1);
    displayList(list);


    return 0;
}

void append(LIST* list, int data) {
    LIST* ptr;
    for (ptr = list; *ptr != NULL; ptr = &(*ptr)->link) {}

    LIST temp = (LIST)malloc(sizeof(Node));
    if (temp != NULL) {
        temp->data = data;
        temp->link = NULL;
        *ptr = temp;
    }
}

void displayList(LIST list) {
    while (list != NULL) {
        printf("%d -> ", list->data);
        list = list->link;
    }
    printf("NULL\n");
}