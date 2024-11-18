#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    void* Previous;
    int value;
    void* Next;
} QueueNode;

typedef struct {
    int size;
    QueueNode* Bottom;
    QueueNode* Top;
} Queue;

void QueuePush(Queue* queue, int value);
int QueueShift (Queue* queue, int* value);
void QueueFlush (Queue* queue);
Queue createQueue ();

#endif