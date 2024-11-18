#include <stdio.h>
#include <stdlib.h>
#include "testQueue.h"

void TestQueuePush (TestQueue* queue, Test* value) {
    TestQueueNode* node = (TestQueueNode*)malloc(sizeof(TestQueueNode));

    if (node == NULL) {
        printf("Couldn't allocate memory for a new TestQueueNode on queue of size %d\n", queue->size);
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

int TestQueueShift (TestQueue* queue, Test* value) {
    if (!queue->Bottom) return -1;

    TestQueueNode* node = queue->Bottom;
    queue->Bottom = node->Next;

    value = node->value;
    free(node);

    queue->size--;
    if (queue->size == 0) queue->Top = NULL;

    return 0;
}

void TestQueueFlush (TestQueue* queue) {
    while (!TestQueueShift(queue, &(Test){}));
}

TestQueue createTestQueue () {
    return (TestQueue){.Bottom = NULL, .Top = NULL, .size = 0};
}
