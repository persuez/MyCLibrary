#include "stack.h"

#include <stdio.h>

int main()
{
    Stack s;
    int i = 1, j = 2, k = 3;
    void display(void * val)
    {
        int *elem = val;
        printf("%d ", *elem);
    }
    StackNew(&s, sizeof(int), NULL);
    StackPush(&s, &i);
    StackPush(&s, &j);
    StackPush(&s, &k);
    StackDisplay(&s, display);
    int v;
    StackPop(&s, &v);
    StackDisplay(&s, display);
    printf("%d\n", v);
    StackDepose(&s);

    return 0;
}
