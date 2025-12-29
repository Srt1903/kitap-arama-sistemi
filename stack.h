#ifndef STACK_H
#define STACK_H


#define MAX_STACK 100


typedef enum {
    ACTION_SORT,
    ACTION_ADD,
    ACTION_DELETE
} ActionType;


typedef struct {
    ActionType type;
    int index;   // ilgili kitap index’i
} Action;


typedef struct {
    Action items[MAX_STACK];
    int top;
} Stack;


void initStack(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s, Action a);
Action pop(Stack* s);


#endif