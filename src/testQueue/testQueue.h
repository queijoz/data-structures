#ifndef TEST_QUEUE_H
#define TEST_QUEUE_H

#include "../test/test.h"

typedef struct {
    void* Previous;
    Test* value;
    void* Next;
} TestQueueNode;

typedef struct {
    int size;
    TestQueueNode* Bottom;
    TestQueueNode* Top;
} TestQueue;

void TestQueuePush (TestQueue* queue, Test* value);
int TestQueueShift (TestQueue* queue, Test* value);
void TestQueueFlush (TestQueue* queue);
TestQueue createTestQueue ();

#endif