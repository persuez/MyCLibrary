#ifndef SEARCH_H_
#define SEARCH_H_

/* provide a linear search method to search a key 
 * if it is in the array.If find it successfully, 
 * return its first position.If not, and return null
 */
void *linearSearch(void *base, int n, int elemSize,
        void *key, int (*cmp)(void *, void *));

#include "search.inc"
#endif
