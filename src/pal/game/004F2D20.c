/* cflags: -mno-split-addresses */
#include "common.h"

extern char *D_00221FD4;
extern int func_004F28B0(void *, void *);
/* Package the position relative to the owner. */
int func_004F2D20(char *p, long a, long b, int c, int d)
{
    struct Type1 {
        long a, b;
        int c, d;
    } s;
    s.a = a;
    s.b = b;
    s.c = c - *(int *)(p + 0x48);
    s.d = d;
    return func_004F28B0(D_00221FD4 + 0x48, &s);
}
