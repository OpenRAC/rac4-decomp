#include "common.h"

extern int D_003DDE48[][10];
/* Return an indexed value or the unchanged identity. */
int func_00547BB0(int a, int b)
{
    if ((unsigned)(b + 1) > 10)
        return 0;
    if (b == -1)
        return a;
    return D_003DDE48[a][b];
}
