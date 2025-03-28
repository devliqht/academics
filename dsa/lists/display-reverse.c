#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Linkedlist{
    struct Node *head;
    int ctr;
};

void createList(struct Linkedlist **list, int n){

    int data;
    int ctr = 0;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* tmp;
    
    if((*list)->head == NULL){

        printf("Input data for node 1: ");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        (*list)->head = newNode;
        tmp = (*list)->head;
        ctr++;
    }
    do{
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
            printf("Input data for node %d: ", ctr+1);
            scanf("%d", &data);
            newNode->data = data;
            newNode->next = NULL;

            tmp->next = newNode;
            tmp = tmp->next;
            ctr++;
        }while(ctr < n);

    (*list)->ctr = n;

}

void displayList(struct Linkedlist **list){
    struct Node* tmp = (*list)->head;

    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }

}

void displayreverseList(struct Linkedlist **list){

    int revctr = (*list)->ctr;
    for(int i = 0; i < (*list)->ctr; i++){
        struct Node* tmp = (*list)->head;
        int ctr = 0;
        while(tmp->next != NULL && ctr < revctr){
            tmp = tmp->next;
            ctr++;
        }
        printf("%d ", tmp->data);
        revctr--;
    }
}

int main()
{
    struct Linkedlist *list;

    list->head = NULL;
    list->ctr = 0;

    int n;
    printf("Input the number of nodes: ");
    scanf("%d", &n);

    createList(&list, n);

    displayList(&list);

    printf("\n");

    displayreverseList(&list);

}