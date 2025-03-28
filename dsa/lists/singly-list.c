#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* TRAVERSAL FUNCTIONS */
void displayList(Node** list);

/* UTILITY FUNCTIONS */
int getSize(Node** list);
int isEmpty(Node** list);
void freeList(Node** list);

/* SEARCHING FUNCTIONS */
int searchValue(Node** list, int index);
int searchPosition(Node** list, int val);
Node* getNodeAtPosition(Node** list, int index);

/* INSERTION FUNCTIONS */
void insertFirst(Node** list, int value);
void append(Node** list, int value);
void insertSomewhere(Node** list, int value, int position);

/* DELETION FUNCTIONS */
void deleteFirst(Node** list);
void deleteLast(Node** list);
void deleteSomewhere(Node** list, int position);
void deleteByValue(Node** list, int val);


/* MODIFICATION FUNCTIONS */
void updateValueByPosition(Node** list, int position, int new_val);
void updateValueBySearch(Node** list, int search, int new_val);
int swapNodes(Node* x, Node* y);

/* ADVANCED FUNCTIONS */
void bubbleSort(Node** list);
int reverseList(Node** list);
int mergeLists(Node** L_first, Node** L_second);
void detectCycle(Node** list);


int main(void) {
    Node* head = NULL;
    displayList(&head);

    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertFirst(&head, 30);
    insertFirst(&head, 40);
    insertSomewhere(&head, 50, 4);
    displayList(&head);

    freeList(&head);
    displayList(&head);

    append(&head, 200);
    append(&head, 300);
    append(&head, 400);
    append(&head, 500);
    displayList(&head);
    deleteFirst(&head);
    displayList(&head);

    insertFirst(&head, 100);
    deleteLast(&head);
    displayList(&head);

    deleteSomewhere(&head, 1);
    displayList(&head);

    append(&head, 600);
    append(&head, 700);
    deleteSomewhere(&head, 3);
    displayList(&head);

    printf("\nPosition 2 value: %d\n", searchValue(&head, 2));
    printf("Position 4 value: %d\n", searchValue(&head, 4));
    printf("Position of Value 400: %d\n", searchPosition(&head, 400));
    printf("Position of Value 900: %d\n", searchPosition(&head, 900));

    deleteByValue(&head, 600);
    displayList(&head);

    insertFirst(&head, 50);
    insertFirst(&head, 95);
    displayList(&head);

    updateValueByPosition(&head, 0, 60);
    displayList(&head);
    updateValueBySearch(&head, 100, 105);
    displayList(&head);

    bubbleSort(&head);
    displayList(&head);


    return 0;
}


Node* createNode(int data) {
    Node* curr = (Node*)malloc(sizeof(Node));
    curr->data = data;
    curr->next = NULL;
    return curr;
}

void displayList(Node** list) {
    Node* curr = *list;

    putchar('\n');
    while (curr != NULL) {
        printf("%d", curr->data);
        printf(" -> ");
        curr = curr->next;
    }
    printf("NULL\n");
    printf("Size: %d\n", getSize(list));
}

int getSize(Node** list) {
    int count = 0;
    Node* curr = *list;
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }
    return count;
}

int isEmpty(Node** list) {
    return *list == NULL;
}

void freeList(Node** list) {
    Node* curr = *list;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);  // Free memory of the removed node
    }
    *list = NULL;
}

int searchValue(Node** list, int index) {
    Node* curr = *list;
    int count = 0;

    if (isEmpty(list)) return -1;
    if (index < 0) return -1;

    while (curr != NULL && count < index) {
        curr = curr->next;
        count++;
    }

    // Given LL: 100 -> 400 -> 600 -> NULL, Find the value of index 2
    // curr = 100, curr != NULL, 0 < 2
    // curr = 400, curr != NULL, 1 < 2
    // curr = 600, curr != NULL, 2 < 2

    if (curr != NULL) return curr->data;
    
    return -1;
}

int searchPosition(Node** list, int val) {
    Node* curr = *list;
    int count = 0;
    while (curr != NULL) {
        if (curr->data == val) return count;
        curr = curr->next;
        count++;
    }
    return -1;
}

Node* getNodeAtPosition(Node** list, int index) {
    Node* curr = *list;
    int count = 0;

    if (isEmpty(list)) return NULL;
    if (index < 0) return NULL;

    while (curr != NULL && count < index) {
        curr = curr->next;
        count++;
    }

    return curr;
}

void insertFirst(Node** list, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) return;

    if (isEmpty(list)) {
        *list = newNode;
    } else {
        // At insertFirst(), every newNode becomes the new head, and it's next pointer now points to the old head.
        newNode->next = *list; // Let the newNode point to the old head
        *list = newNode; // Let the head be assigned to newNode
    }
}

void append(Node** list, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) return;

    if (isEmpty(list)) {
        *list = newNode; // If head is empty (Empty list), then head becomes newNode.
    } else {
        Node* curr = *list; 
        // Traverse the linked list, check if the current node's next is NULL, if it's not, continue.
        // If it's NULL, it stops at the current node.
        while (curr->next != NULL) { 
            curr = curr->next;
        }
        // The current node's next now points to newNode.
        curr->next = newNode;
    }
}

void insertSomewhere(Node** list, int value, int position) {
    int count = 0;
    Node* newNode = createNode(value);
    if (newNode == NULL) return;

    // If position 0 (head), execute insertFirst. Free the newNode since it wasn't used, and return.
    if (position == 0) {
        insertFirst(list, value);
        free(newNode);
        return;
    }

    Node* curr = *list;

    while (curr != NULL && count < position - 1) {
        curr = curr->next;
        count++;
        // LL: 40 -> 30 -> 20 -> 10 -> NULL
        // Let's say insert 50 at position 3.
        // Let's start at list->head which is 40.
        // 40 is NOT null, and count 0 is also less than 2 (3-1). Execute.
        // 30 is NOT null, and count 1 is also less than 2. Execute.
        // 20 is NOT null, but count 2 is not less than 2. Stop.
    }
    if (curr == NULL) return; // Check if curr is null, which means it's out-of-bounds access.

    // Set the next of the newNode to the current node's next.
    newNode->next = curr->next;

    // Set the previous node's next to the newNode, essentially "re-routing" the path.
    curr->next = newNode;
}

void deleteFirst(Node** list) {
    if (isEmpty(list)) return; // Check if list is empty.

    Node* curr = *list;
    *list = curr->next;
    free(curr);
}

void deleteLast(Node** list) {
    if (isEmpty(list)) return; // If the list is empty, return.

    if ((*list)->next == NULL) { // If the list only has one node (the head), then delete the head (free) and point it to NULL.
        free(*list);
        *list = NULL;
        return;
    }

    Node* curr = *list, *prev = NULL; // We start at the head
    while (curr->next != NULL) { // We check if the next of the current node is null, if it's not:
        prev = curr; // Save the current node as the previous node
        curr = curr->next; // Set the current node to the next.
    }
    // Given LL: 100 -> 300 -> 400 -> 500 -> NULL
    // 1st: curr = 100, prev = NULL, curr->next 300 is NOT NULL, thus prev = 100, curr = 300
    // 2nd: curr = 300, prev = 100, curr->next 400 is NOT NULL, thus prev = 300, curr = 400
    // 3rd: curr = 400, prev = 300, curr->next 500 is NOT NULL, thus prev = 400, curr = 500
    // 4th: curr = 500, prev = 400, curr->next IS NULL, STOP
    
    // Free curr which is 500
    free(curr);

    // Set the prev (400) to point to NULL, signifying the end of a list.
    prev->next = NULL;
}

void deleteSomewhere(Node** list, int position) {
    Node* curr = *list;
    int count = 0;

    // If empty, return
    if (isEmpty(list)) return;

    // Invalid position
    if (position < 0) return;

    // If position 0, delete the head 
    if (position == 0) {
        deleteFirst(list);
        return;
    }

    // Traverse the linked list until the node before the position.
    while (curr != NULL && count < position - 1) {
        curr = curr->next;
        count++;
    }

    // Example: 100 -> 400 -> 600 -> 700 -> NULL, delete POSITION 3
    // curr = 100, curr != NULL, 0 < 2 (3-1)
    // curr = 400, curr != NULL, 1 < 2 (3-1)
    // curr = 600, curr != NULL, 2 < 2 FALSE, STOP
    // Result: curr = 600 (position 2, one before POSITION 3)

    if (curr == NULL || curr->next == NULL) return;  // Out-of-bounds check if ever user gives invalid position

    // Create a temp node that holds curr->next (700 in this case)
    Node* temp = curr->next;

    // curr->next should now point to temp->next, essentially skipping temp
    // Let's say 600 -> 700 -> 800 -> NULL
    // 600 is curr, temp is 700 (curr->next).
    // 600 next pointer is currently pointing to 700, and we need to change that to point to 800.
    // temp->next is 800 (since temp is 700) thus curr->next now points to 800 (temp->next).
    curr->next = temp->next;

    // Free 700 (temp) essentially deleting it.
    free(temp);
}


void deleteByValue(Node** list, int val) {
    // The functions are now built it's so easy to implement new ones now?
    int pos = searchPosition(list, val);
    if (pos != -1) deleteSomewhere(list, pos);
}

void updateValueByPosition(Node** list, int position, int new_val) {
    Node* update = getNodeAtPosition(list, position);
    if (update != NULL) {
        update->data = new_val;
    }
}

void updateValueBySearch(Node** list, int search, int new_val) {
    int pos = searchPosition(list, search);
    Node* update = getNodeAtPosition(list, pos);
    if (update != NULL) {
        update->data = new_val;
    }
}

int swapNodes(Node* x, Node* y) {
    if (x && y) {
        int temp = x->data;
        x->data = y->data;
        y->data = temp;
        return 1;
    }
    return 0;
}

void bubbleSort(Node** list) {
    if (isEmpty(list)) return;

    int swapped = 1;
    while (swapped) {
        Node* curr = *list; // On every pass, always start at the head
        swapped = 0;
        while (curr->next != NULL) { 
            // The above while condition is similar to:
            // for (int i = 0; i < size - 1; i++);
            // Since we're checking curr->next if null, essentially stopping 
            // at the Node before NULL.
            if (curr->data < curr->next->data) { // Standard bubbleSort (descending <)
                swapNodes(curr, curr->next);
                swapped = 1;
            }
            curr = curr->next;
        }
    }
}