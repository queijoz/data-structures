#ifndef ARRAY_H
#define ARRAY_H

#include "../variant/variant.h"

struct Array;

typedef struct Array {
    Variant* start;
    int size;

    Variant* (*Get)(struct Array*, int);
    int (*Search)(struct Array*, Variant*);
    void (*Set)(struct Array*, int, Variant*);
} Array;

Array CreateArray(int size);

#endif