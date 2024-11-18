// filename=stack ./watch
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* next;
    int value;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

void Push (Stack* stack, int value) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (node == NULL) {
        printf("Couldn't allocate memory for a new Node on stack of size %d\n", stack->size);
        exit(1);
    }

    node->next = stack->top;
    node->value = value;

    stack->size++;
    stack->top = node;
}

int Pop (Stack* stack) {
    if (stack->top == NULL) return NULL;

    Node* node = stack->top;
    int value = node->value;

    stack->size--;
    stack->top = node->next;

    free(node);
    return value;
}

Stack createStack () {
    return (Stack){.top = NULL, .size = 0};
}

int main () {

    Stack stack = createStack();

    int first = 69;
    int second = 420;

    Push(&stack, first);
    Push(&stack, second);

    int current = Pop(&stack);
    printf("expected %d, got %d\n", second, current);

    current = Pop(&stack);
    printf("expected %d, got %d\n", first, current);

    current = Pop(&stack);
    printf("expected %s, got %s\n", "(null)", (char*)current);
    return 0;
}