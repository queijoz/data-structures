// filename=stackAlloc ./watch
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header/stack.h"

const int DEBUG = 1;

const STACK_TYPES_DEFINITION STACK_TYPES = {
    .charType = 'c',
    .floatType = 'f',
    .integerType = 'i'
};

typedef struct {
    int size;
    int maxSize;
    int sizeofType;
    char type;
    void* arr;
} Stack;

void* GetElement (Stack* stack, int index) {
    printf("value getElem: %f\n", *((float*)stack->arr + (index * stack->sizeofType)));
    if (stack->type == STACK_TYPES.charType) return (char*)stack->arr + (index * stack->sizeofType);
    if (stack->type == STACK_TYPES.floatType) return (float*)stack->arr + (index * stack->sizeofType);
    if (stack->type == STACK_TYPES.integerType) return (int*)stack->arr + (index * stack->sizeofType);
}

void Push (Stack* stack, void* value) {
    stack->size++;

    if (stack->size > stack->maxSize) {
        if (DEBUG) printf("DEBUG: stack size exceeded. increasing size from %d to %d\n", stack->maxSize, stack->maxSize*2);

        stack->maxSize *= 2;

        void* reallocResult = realloc(stack->arr, stack->sizeofType * stack->maxSize);

        if (reallocResult == NULL) {
            puts("ERROR: couldn't realloc stack.");
            exit(1);
        }

        if (stack->type == STACK_TYPES.charType) stack->arr = (char*) reallocResult;
        if (stack->type == STACK_TYPES.floatType) stack->arr = (float*) reallocResult;
        if (stack->type == STACK_TYPES.integerType) stack->arr = (int*) reallocResult;
    }

    if (stack->type == STACK_TYPES.charType) *(char*)GetElement(stack, stack->size - 1) = *(char*)value;
    if (stack->type == STACK_TYPES.floatType) *(float*)GetElement(stack, stack->size - 1) = *(float*)value;
    if (stack->type == STACK_TYPES.integerType) *(int*)GetElement(stack, stack->size - 1) = *(int*)value;
}

void* Pop (Stack* stack) {
    if (stack->size == 0) return NULL;

    void* value = GetElement(stack, --stack->size);
    printf("value: %f\n", *(float*)value);

    if (stack->size < stack->maxSize / 2) {
        if (DEBUG) printf("DEBUG: stack size is less than half. decreasing size from %d to %d\n", stack->maxSize, stack->maxSize/2);

        stack->maxSize /= 2;
        void* reallocResult = realloc(stack->arr, stack->sizeofType * stack->maxSize);

        if (reallocResult == NULL) return value;

        if (stack->type == STACK_TYPES.charType) stack->arr = (char*) reallocResult;
        if (stack->type == STACK_TYPES.floatType) stack->arr = (float*) reallocResult;
        if (stack->type == STACK_TYPES.integerType) stack->arr = (int*) reallocResult;
    }

    return value;
}

Stack createStack(char type) {

    int sizeofType = 0;

    if (type == STACK_TYPES.charType) sizeofType = sizeof(char);
    if (type == STACK_TYPES.floatType) sizeofType = sizeof(float);
    if (type == STACK_TYPES.integerType) sizeofType = sizeof(int);

    if (sizeofType == 0) {
        puts("Unknown type found while trying to create a Stack");
        exit(1);
    }

    void* arr;

    if (type == STACK_TYPES.charType) arr = (char*)malloc(sizeofType);
    if (type == STACK_TYPES.floatType) arr = (float*)malloc(sizeofType);
    if (type == STACK_TYPES.integerType) arr = (int*)malloc(sizeofType);

    return (Stack){0, 1, sizeofType, type, arr};
}

int main () {

    Stack stack = createStack(STACK_TYPES.floatType);

    float first = 2.74;
    float second = 3.69;
    float third = 4.82;

    Push(&stack, &first);
    Push(&stack, &second);

    printf("first: %f\n", *(float*)GetElement(&stack, 0));
    printf("second: %f\n", *(float*)GetElement(&stack, 1));

    Push(&stack, &third);

    printf("third: %f\n", *(float*)GetElement(&stack, 2));

    float pop = *(float*)Pop(&stack);
    printf("pop: %f\n", pop);

    return 0;
}
