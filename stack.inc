#include "stack.h"

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

void StackNew(Stack *s, int elemSize, void (*freefn)(void *))
{
    assert(s != NULL);

    s->allocLength = 4;
    s->logLength = 0;
    s->elemSize = elemSize;
    s->elems = malloc(4 * elemSize);
    assert(s->elems != NULL);
    s->freefn = freefn;
}

void StackDepose(Stack *s)
{
    assert(s != NULL);

    if (s->freefn != NULL) {
        for (int i = 0; i < s->logLength; i++) {
            s->freefn((char *)s->elems + i * s->elemSize);
        }
    }

    free(s->elems);
}

static void StackGrow(Stack *s)
{
    s->allocLength *= 2;
    s->elems = realloc(s->elems, s->allocLength * s->elemSize);
    assert(s->elems != NULL);
}

void StackPush(Stack *s, void *elemAddr)
{
    assert(s != NULL);

    if (s->logLength == s->logLength) {
        StackGrow(s);
    }

    void *dest = (char *)s->elems + s->logLength * s->elemSize;
    memcpy(dest, elemAddr, s->elemSize);
    s->logLength++;
}

void StackPop(Stack *s, void *elem)
{
    s->logLength--;
    
    void *src = (char *)s->elems + s->logLength * s->elemSize;
    memcpy(elem, src, s->elemSize);
}

void StackDisplay(Stack *s, void (*display)(void *))
{
    assert(s != NULL);

    printf("Tha elements of stack is:\n");
    for (int i = 0; i < s->logLength; i++) {
        display((char *)s->elems + i * s->elemSize);
    }
    printf("\n");
}
