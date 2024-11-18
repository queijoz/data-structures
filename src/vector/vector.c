// filename=vector ./watch
#include <stdio.h>
#include <stdlib.h>

// MAIN THING HERE IS TO PROBABLY NOT FALL INTO MAKING A 'PUSH' METHOD
// IF AT ANY POINT AN ASSIGN HAPPENS TO AN OUT OF BOUNDS INDEX,
// JUST REALLOC AND CALL IT A DAY

typedef struct {
    int* start;
    int size;
} Vector;

int* GetPointer (Vector* vec, int index) {
    if (index >= vec->size) return NULL;
    return vec->start + index;
}

int Get (Vector* vec, int index) {
    if (index >= vec->size) return 0;
    return *GetPointer(vec, index);
}

void Set (Vector* vec, int index, int value) {
    if (index >= vec->size) {
        int* reallocResult = realloc(vec->start, 1 + index);

        if (reallocResult == NULL) {
            printf("Couldn't realloc vector of size %d to size %d.", vec->size, index);
            exit(1);
        }

        vec->size = 1 + index;
        vec->start = reallocResult;        
    }

    *GetPointer(vec, index) = value;
}

Vector createVector () {
    return (Vector){.start = malloc(sizeof(int)), .size = 1};
}

int main () {

    Vector vector = createVector();

    int index = 69;
    int value = 69;

    Set(&vector, index, value);
    printf("expected: %d, got: %d\n", value, Get(&vector, index));

    free(vector.start);
    return 0;
}