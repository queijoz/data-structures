#ifndef VARIANT_H
#define VARIANT_H

typedef struct {
    void* Value;
    const char* Type;
} Variant;

void freeVariant (Variant* variant);
int printVariant (Variant* variant);
int compareVariant (Variant* a, Variant* b);

Variant* getIntVariant (int value);
Variant* getCharVariant (char value);
Variant* getStringVariant (char* value);
Variant* getFloatVariant (float value);

#endif