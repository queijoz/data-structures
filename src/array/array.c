#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// TODO:
// [*] array de inteiros;
// [*] busca (function Search(int value));
// [*] multi-tipos;
// [ ] handle out-of-bounds;

Variant* GetPointer (Array* arr, int index) {
    if (index >= arr->size) return NULL; // maybe throw an error?

    return arr->start + index;
}

Variant* Get (Array* arr, int index) {
    if (index >= arr->size) return 0; // maybe throw an error?
    return (Variant*)GetPointer(arr, index);
}

void Set (Array* arr, int index, Variant* variant) {
    if (index >= arr->size) return; // maybe throw an error?
    *(Variant*)GetPointer(arr, index) = *variant;
}

int Search (Array* arr, Variant* variant) {
    for (int i = 0; i < arr->size; i++)
        if (compareVariant(Get(arr, i), variant)) return i;
    return -1;
}

Array CreateArray(int size) {
    return (Array){
        .start = malloc(sizeof(Variant) * size),
        .size = size,
        .Get = &Get,
        .Set = &Set,
        .Search = &Search
    };
}