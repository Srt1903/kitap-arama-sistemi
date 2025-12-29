#include "stack.h"


void initStack(Stack* s) {
    s->top = -1;
}


int isEmpty(Stack* s) {
    return s->top == -1;
}


void push(Stack* s, Action a) {
    if (s->top < MAX_STACK - 1)
        s->items[++s->top] = a;
}


Action pop(Stack* s) {
    Action empty = { -1, -1 };
    if (isEmpty(s)) return empty;
    return s->items[s->top--];
}