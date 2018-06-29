#include "ptrslist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    PtrSList list;
    void display(void *elem)
    {
        char *key = *(char **)elem;
        printf("%s ", key);
    }
    void freefn(void *elem)
    {
        free(*(char **)elem); 
    }
    char *i = strdup("abc"), *j = strdup("def"), *k = strdup("ghifjk");
    PtrSListNew(&list, sizeof(char *), freefn);
    PtrSListHInsert(&list, &i);
    PtrSListHInsert(&list, &j);
    PtrSListHInsert(&list, &k);
    PtrSListDisplay(&list, display);
    PtrSListDepose(&list);
    return 0;
}
