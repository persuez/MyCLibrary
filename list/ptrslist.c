#include "ptrslist.h"
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void PtrSListNew(PtrSList *list, int elemSize, void (*freefn)(void *))
{
    assert(list != NULL);
    list->head = NULL;
    list->length = 0;
    list->elemSize = elemSize;
    list->freefn = freefn;
}

void PtrSListHInsert(PtrSList *list, void *elem)
{
    assert(list != NULL);

    SNode *node = malloc(sizeof(SNode *));
    assert(node != NULL);
    node->elem = malloc(list->elemSize);
    assert(node->elem != NULL);
    memcpy(node->elem, elem, list->elemSize);

    if (list->head == NULL) {
        list->head = node;
        node->next = NULL; 
    } else {
        SNode *head_next = list->head;
        list->head = node;
        node->next = head_next;
    }
    list->length++;
}

void PtrSListDepose(PtrSList *list)
{
    assert(list != NULL);

    SNode *curr = list->head, *next;
    if (list->head != NULL && list->freefn == NULL) {
        for (int i = 0; i < list->length; i++) {
            next = curr->next;
            free(curr->elem);
            free(curr);
            curr = next; 
        }
    } else if (list->head != NULL && list->freefn != NULL) {
        for (int i = 0; i< list->length; i++) {
            next = curr->next;
            list->freefn(curr->elem);
            free(curr->elem);
            free(curr);
            curr = next;
        }
    }
    list->length = 0;
}

void PtrSListDisplay(PtrSList *list, void (*display)(void *))
{
    assert(list != NULL);
    SNode *node = list->head;
    printf("the element(s) of the list:\n");
    if (list->head != NULL) {
        for (int i = 0; i < list->length; i++) {
            display(node->elem);
            node = node->next;
        }
        printf("\n");
    }
}
