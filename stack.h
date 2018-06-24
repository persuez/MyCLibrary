#ifndef STACK_H_
#define STACK_H_

typedef struct {
    int allocLength;
    int logLength;
    int elemSize;
    void *elems;
    void (*freefn)(void *);
}Stack;

/* constructor */
void StackNew(Stack *s, int elemSize, void (*freefn)(void *));

/* destructor */
void StackDepose(Stack *s);

/* push */
void StackPush(Stack *s, void *elemAddr);

/* Pop */
void StackPop(Stack *s, void *elem);

/* display */
void StackDisplay(Stack *s, void (*display)(void *));

#include "stack.inc"

#endif

