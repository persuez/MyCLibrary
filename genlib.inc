#include "genlib.h"
#include <stdlib.h>
#include <string.h>

void mySwap(void *elem1, void * elem2, int elemSize)
{
    char *buffer = (char *)malloc(elemSize);
    memcpy(buffer, elem1, elemSize);
    memcpy(elem1, elem2, elemSize);
    memcpy(elem2, buffer, elemSize);
    free(buffer);
}
