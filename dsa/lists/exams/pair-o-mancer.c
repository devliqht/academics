#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* link;
} Node;

void sortPairs(Node** list);
void getInput(Node** list);
void display(Node* list) {
    while (list != NULL) {
        printf("%d ", list->data);
        list = list->link;
    }
    printf("\n");
}

int main(void) {
    Node* list = NULL;
    int n;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    printf("Enter %d elements: \n", n);

    for (int i = 0 ; i < n ; i++) {
        getInput(&list);
    }
    sortPairs(&list);
    return 0;
}

void swap(Node* x, Node* y) {
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

void sortPairs(Node** list) {
     Node* head = *list;
     Node* out_trav = *list;
    
     int swapped = 1;
     while (out_trav->link != NULL && swapped) {
         swapped = 0;
         Node* in_trav = *list;
         while (in_trav->link != NULL) {
             if (in_trav->data > in_trav->link->data) {
                 swap(in_trav, in_trav->link);
                 swapped = 1;
             }
             in_trav = in_trav->link;
         }
         out_trav = out_trav->link;
     }

     Node* ptrav = *list;
     printf("Closest Pairs: \n");
     while (ptrav != NULL) {
        if (ptrav->link != NULL) {
            printf("(%d, %d)\n", ptrav->data, ptrav->link->data);
        } else {
            printf("(%d, -)\n", ptrav->data);
            break;
        }

        if (ptrav->link->link != NULL) {
            ptrav = ptrav->link->link;
        } else {
            ptrav = ptrav->link;
        }
     }
}
void getInput(Node** list) {
    int data;
    scanf("%d", &data);

    Node* temp = malloc(sizeof(Node));
    if (temp != NULL) {
        temp->data = data;
        temp->link = NULL;
        if (*list == NULL) {
            *list = temp;
        } else {
            Node* trav = *list;
            while (trav->link != NULL) {
                trav = trav->link;
            }
            trav->link = temp;
        }
    }
}
