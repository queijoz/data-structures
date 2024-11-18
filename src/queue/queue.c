// filename=queue ./watch
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Push (Queue* queue, int value) {
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));

    if (node == NULL) {
        printf("Couldn't allocate memory for a new QueueNode on queue of size %d\n", queue->size);
        exit(1);
    }

    node->Next = NULL;
    node->value = value;
    node->Previous = queue->Top;

    if(queue->Top) queue->Top->Next = node;

    queue->Top = node;
    queue->size++;

    if (!queue->Bottom) queue->Bottom = queue->Top;
}

int Shift (Queue* queue, int* value) {
    if (!queue->Bottom) return -1;

    QueueNode* node = queue->Bottom;
    queue->Bottom = node->Next;

    *value = node->value;
    free(node);

    queue->size--;
    if (queue->size == 0) queue->Top = NULL;

    return 0;
}

void Flush (Queue* queue) {
    while (!Shift(queue, &(int){0}));
}

Queue createQueue () {
    return (Queue){.Bottom = NULL, .Top = NULL, .size = 0};
}

int main () {

    int value, shift;
    Queue queue = createQueue();

    value = 42;
    Push(&queue, value);
    Shift(&queue, &shift);
    printf("expected %d, got %d\n", value, shift);

    value = 69;
    Push(&queue, value);
    Shift(&queue, &shift);
    printf("expected %d, got %d\n", value, shift);

    Push(&queue, 1);
    Push(&queue, 2);
    Push(&queue, 3);
    Push(&queue, 4);
    Flush(&queue);
    printf("expected %d, got %d\n", 0, queue.size);

    return 0;
}