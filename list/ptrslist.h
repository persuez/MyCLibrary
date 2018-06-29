#ifndef PTRSLIST_H_
#define PTRSLIST_H_

#include "snode.h"

typedef struct {
    SNode *head;
    int length;
    int elemSize;
    void (*freefn)(void *);
}PtrSList;

/* initialise a list */
void PtrSListNew(PtrSList *list, int elemSize, void (*)(void *));

/* insert an element from list's head */
void PtrSListHInsert(PtrSList *list, void *elem);

/* display a list */
void PtrSListDisplay(PtrSList *list, void (*display)(void *));

/* free a list */
void PtrSListDepose(PtrSList *list);

#endif
