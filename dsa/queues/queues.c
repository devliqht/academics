#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int front, rear;
    int capacity;
    int* arr;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;

    q->capacity = n;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(q->capacity*sizeof(int));
    if (!q->arr) {
        free(q);
        return NULL;
    }
    return q;
}

int isQueueEmpty(Queue* q) {
    return (q->front == -1);
}

int isQueueFull(Queue* q) {
    return (q->rear == q->capacity - 1);
}

void enqueue(Queue* q, int elem) {
    if (isQueueFull(q)) {
        printf("Enqueue Error: Queue is full.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
    }
    q->arr[++q->rear] = elem;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Dequeue Error: Queue is empty.\n");
        return INT_MIN;
    }
    int dequeued = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }

    return dequeued;
}

void printQueueInfo(Queue* q) {
    puts("");

    printf("Queue Info: \n[ ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("]\n");
    printf("Current front index: %d\n", q->front);
    printf("Current rear index: %d\n", q->rear);
    if (isQueueFull(q)) printf("Full\n");
    if (isQueueEmpty(q)) printf("Empty\n");

    puts("");
}

void freeQueue(Queue* q) {
    free(q->arr);
    free(q);
}

int main(void) {
    int size;
    printf("[Queue]: Enter queue size: ");
    scanf("%d", &size);
    Queue* q = createQueue(size);
    printf("[Queue]: Creation successful.\n");
    printf("[Queue]: Size of %d\n", q->capacity);
    printQueueInfo(q);

    int x, y, z;
    printf("[Queue]: Enqueue 3 items: ");
    scanf("%d %d %d", &x, &y, &z);

    enqueue(q, x); enqueue(q, y); enqueue(q, z);
    printf("[Queue]: Enqueued 3 items\n");
    printQueueInfo(q);

    printf("[Queue]: Dequeueing 1 item: %d\n", dequeue(q));
    printQueueInfo(q);

    printf("[Queue]: Dequeueing 2 items: %d %d\n", dequeue(q), dequeue(q));
    printQueueInfo(q);

    printf("[Queue]: Dequeueing an item: %d\n", dequeue(q));

    printf("[Queue]: Enqueueing 5 items: 1, 2, 3, 4, 5\n");
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printQueueInfo(q);

    printf("[Queue]: Enqueueing an item: \n");
    enqueue(q, 6);

    freeQueue(q);

    return 0;
}
