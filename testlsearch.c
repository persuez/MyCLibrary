#include "search.h"
#include <stdio.h>

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int key;
    scanf("%d", &key);
    int cmp(void *addr1, void * addr2) {
        int *elem1 = addr1;
        int *elem2 = addr2;

        return *elem1 == *elem2;
    }
    if (linearSearch(array, 5, sizeof(int), &key, cmp)) {
        printf("find!\n");
    } else {
        printf("not find!\n");
    }

    return 0;
}
