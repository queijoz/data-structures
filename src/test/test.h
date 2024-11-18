#ifndef TEST_H
#define TEST_H

#include "../variant/variant.h"

enum TestStatus { Failed, Passed };

typedef struct {
    char Name[200];
    enum TestStatus Status;
    Variant* Expected;
    Variant* Received;
} Test;

int test(Test tests[], int size);

#endif