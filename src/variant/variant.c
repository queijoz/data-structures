#include <stdio.h>
#include <stdlib.h>
#include "variant.h"

const char INT_TYPE[] = "int";
const char CHAR_TYPE[] = "char";
const char STRING_TYPE[] = "string";
const char FLOAT_TYPE[] = "float";

void freeVariant(Variant* variant) {
    free(variant->Value);
    free(variant);
}

int printVariant (Variant* variant) {
    if (variant->Type == INT_TYPE) return printf("%d", *(int*)variant->Value);
    if (variant->Type == CHAR_TYPE) return printf("%c", *(char*)variant->Value);
    if (variant->Type == STRING_TYPE) return printf("%s", (char*)variant->Value);
    if (variant->Type == FLOAT_TYPE) return printf("%f", *(float*)variant->Value);
    return -1;
}

int compareVariant (Variant* a, Variant* b) {
    if (a->Type != b->Type) return 0;
    if (a->Type == INT_TYPE) return *(int*)a->Value == *(int*)b->Value;
    if (a->Type == CHAR_TYPE) return *(char*)a->Value == *(char*)b->Value;
    if (a->Type == STRING_TYPE) return (char*)a->Value == (char*)b->Value;
    if (a->Type == FLOAT_TYPE) return *(float*)a->Value == *(float*)b->Value;
    return 0;
}

Variant* getIntVariant (int value) {
    Variant* variant = (Variant*)malloc(sizeof(Variant));
    int* pointer = malloc(sizeof(int));
    *pointer = value;

    *variant = (Variant){.Type = INT_TYPE, .Value = (void*)pointer};
    return variant;
}

Variant* getCharVariant (char value) {
    Variant* variant = (Variant*)malloc(sizeof(Variant));
    char* pointer = (char*)malloc(sizeof(char));
    *pointer = value;

    *variant = (Variant){.Type = CHAR_TYPE, .Value = (void*)pointer};
    return variant;
}

Variant* getStringVariant (char* value) {
    Variant* variant = (Variant*)malloc(sizeof(Variant));
    *variant = (Variant){.Type = STRING_TYPE, .Value = (void*)value};
    return variant;
}

Variant* getFloatVariant (float value) {
    Variant* variant = (Variant*)malloc(sizeof(Variant));
    float* pointer = (float*)malloc(sizeof(float));
    *pointer = value;

    *variant = (Variant){.Type = FLOAT_TYPE, .Value = (void*)pointer};
    return variant;
}
