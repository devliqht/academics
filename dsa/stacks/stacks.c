#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Dynamic Integer Stacks
typedef struct {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int n) {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    newStack->top = -1;
    newStack->capacity = n;
    newStack->array = (int*)malloc(newStack->capacity * sizeof(int));
    return newStack;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

int isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int elem) {
    if (isStackFull(stack)) {
        printf("Stack Overflow: Cannot push %d\n", elem);
        return;
    }
    stack->array[++stack->top] = elem;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow: Cannot pop from an empty stack\n");
        return INT_MIN;
    }
    int popped = stack->array[stack->top--];
    return popped;
}

int peekElement(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty: Nothing to peek\n");
        return INT_MIN; // Error value
    }
    return stack->array[stack->top];
}

void freeStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

int main(void) {
    int n;
    printf("[Creating Stack]: Enter capacity: "); scanf("%d", &n);
    Stack* books = createStack(n);
    printf("Stack Information (Books): \n");
    printf("Capacity: %d\n", books->capacity);
    printf("Top Element: %s\n", (books->top == -1) ? "No Top Element." : "Top Element: 0");
    printf("Is Stack Empty? %s\n", (isStackEmpty(books)) ? "Yes" : "No");

    printf("Push 5, 3, 4, 6, 7, 8, 9 to the stack:\n");
    push(books, 5); push(books, 3); push(books, 4); push(books, 6); push(books, 7); push(books, 8); push(books, 9); // push books 9 shouldnt work.

    printf("Top Element Index: %d\n", books->top);
    printf("Is Stack Empty? %s\n", (isStackEmpty(books)) ? "Yes" : "No");

    printf("Pop element: Popped %d\n", pop(books));
    printf("Top Element Index: %d\n", books->top);

    freeStack(books);
    return 0;
}
