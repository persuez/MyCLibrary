#include "search.h"
#include <stdio.h>
#include <assert.h>

void *linearSearch(void *base, int n, int elemSize, 
        void *key, int (*cmp)(void *, void *))
{
    assert(base != NULL);

    int i = 0;
    for (i = 0; i < n; i++) {
        /* compute the ith element's address */
        void *currnt_addr = 
            (char *)base + i * elemSize;
        if (cmp(currnt_addr, key)) {
            return currnt_addr;
        }
    }
    
    /* not fint */
    return NULL;
}
