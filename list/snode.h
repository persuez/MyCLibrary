#ifndef NODE_H_
#define NODE_H_

typedef struct SNode{
    struct SNode *next;
    void *elem;
}SNode;

#endif
