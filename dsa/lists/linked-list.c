#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
    struct Node* head;
    struct Node* tail;
} LinkedList;

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

void deleteNode(LinkedList* list, int deleted) {
    if (list->head == NULL) {
        printf("Nothing to delete. \n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == deleted && current != list->head && current != list->tail) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            break;
        } else if (current->data == deleted && current == list->head) {
            list->head = current->next;
            if (list->head == NULL) {
                list->tail = NULL;
            } else {
                list->head->prev = NULL;
            }
            break;
        } else if (current->data == deleted && current == list->tail) {
            list->tail = current->prev;
            if (list->tail == NULL) {
                list->head = NULL;
            } else {
                list->tail->next = NULL;
            }
            break;
        }
        current = current->next;
    }
}

void bubbleSort(LinkedList* list) {
    if (!list->head || !list->head->next) return; 
    Node* current = list->head;
    int swapped = 1;
    while (swapped) {
        current = list->head;
        swapped = 0;
        while (current->next != NULL) {
            if (current->data > current->next->data) {
                swap(&current->data, &current->next->data);
                swapped = 1;
            }
            current = current->next;
        }
    }
}

void displayList(LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
           printf(" -> ");
        } else {
            printf("\n");
        }
        current = current->next;
    }
}

int main(void) {
    LinkedList* list = createLinkedList();
    int sample;
    while (sample != -1) {
        printf("Enter data: "); scanf("%d", &sample);
        addNode(list, sample);
    }

    displayList(list);
    bubbleSort(list);
    displayList(list);
    return 0;
}
