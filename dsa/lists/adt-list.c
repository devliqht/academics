#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the list

// Define the ADT List structure
typedef struct {
    int data[MAX_SIZE]; // Array to store list elements
    int size;           // Current number of elements in the list
} List;

// Function to initialize the list
void initList(List *list) {
    list->size = 0; // Start with an empty list
}

// Function to check if the list is empty
int isEmpty(List *list) {
    return list->size == 0;
}

// Function to check if the list is full
int isFull(List *list) {
    return list->size == MAX_SIZE;
}

// Function to insert an element at a specific position
int insert(List *list, int position, int value) {
    if (isFull(list)) {
        printf("Error: List is full!\n");
        return 0;
    }
    if (position < 0 || position > list->size) {
        printf("Error: Invalid position!\n");
        return 0;
    }

    // Shift elements to the right
    for (int i = list->size; i > position; i--) {
        list->data[i] = list->data[i - 1];
    }

    // Insert the new element
    list->data[position] = value;
    list->size++;
    return 1;
}

// Function to delete an element from a specific position
int delete(List *list, int position) {
    if (isEmpty(list)) {
        printf("Error: List is empty!\n");
        return 0;
    }
    if (position < 0 || position >= list->size) {
        printf("Error: Invalid position!\n");
        return 0;
    }

    // Shift elements to the left
    for (int i = position; i < list->size - 1; i++) {
        list->data[i] = list->data[i + 1];
    }

    list->size--;
    return 1;
}

// Function to search for an element
int search(List *list, int value) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == value) {
            return i; // Return the index of the element
        }
    }
    return -1; // Element not found
}

// Function to display the list
void displayList(List *list) {
    if (isEmpty(list)) {
        printf("List is empty!\n");
        return;
    }
    
    printf("List elements: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

// Main function to test the ADT List
int main() {
    List myList;
    initList(&myList);

    insert(&myList, 0, 10); // Insert 10 at index 0
    insert(&myList, 1, 20); // Insert 20 at index 1
    insert(&myList, 1, 15); // Insert 15 at index 1

    printf("After insertion:\n");
    displayList(&myList);

    delete(&myList, 1); // Delete element at index 1

    printf("After deletion:\n");
    displayList(&myList);

    int value = 20;
    int position = search(&myList, value);
    if (position != -1) {
        printf("%d found at index %d\n", value, position);
    } else {
        printf("%d not found in the list\n", value);
    }

    return 0;
}
