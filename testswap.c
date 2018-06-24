#include "genlib.h"
#include <stdio.h>

int main()
{
    int a = 3;
    int b = 4;
    mySwap(&a, &b, sizeof(int));
    printf("%d %d\n", a, b);
    return 0;
}
