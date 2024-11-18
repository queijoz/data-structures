// filename=array ./watch
#include <stdio.h>
#include <stdlib.h>
#include "header/error.h"

// TODO:
// [*] array de inteiros;
// [*] busca (function Search(int value));
// [ ] multi-tipos;
// [ ] handle out-of-bounds;

typedef struct {
    int* start;
    int size;
} Array;

int* GetPointer (Array* arr, int index) {
    if (index >= arr->size) return NULL; // maybe throw an error?

    return arr->start + index;
}

int Get (Array* arr, int index) {
    if (index >= arr->size) return 0; // maybe throw an error?
    return *(int*)GetPointer(arr, index);
}

void Set (Array* arr, int index, int value) {
    if (index >= arr->size) return; // maybe throw an error?
    *(int*)GetPointer(arr, index) = value;
}

int Search (Array* arr, int value) {
    for (int i = 0; i < arr->size; i++)
        if (Get(arr, i) == value) return i;
    return -1;
}

Array CreateArray(int size) {
    return (Array){malloc(sizeof(int) * size), size};
}

/**
 * Checks whether the search method is working properly.
 * It relies on both Get and Set methods, so it ends up testing both functionality as a side effect.
 */
void searchTest () {

    typedef struct {
        int index;
        int value;
    } SearchTest;

    int totalTests = 4;
    SearchTest tests[] = {
        {.index = 0, .value = 7},
        {.index = 1, .value = 8},
        {.index = 2, .value = 9},
        {.index = 3, .value = 11},
    };

    int currentError = -1;
    Error errors[totalTests];
    Array arr = CreateArray(totalTests);

    int passed = 0;
    for (int i = 0; i < totalTests; i++) {

        SearchTest cur = tests[i];
        Set(&arr, cur.index, cur.value);

        if (Search(&arr, cur.value) == cur.index) { passed++; continue; }

        errors[++currentError] = (Error){.Message = ""};
        sprintf(errors[currentError].Message, "Index %d expected to be %d, got %d instead", cur.index, cur.value, Search(&arr, cur.value));
    }

    printf("TESTS: %d passed of %d\n", passed, totalTests);
    for (int i = 0; i <= currentError; i++) puts(errors[i].Message);

    free(arr.start);
}

int main () {

    searchTest();
    return 0;
}