#include "common.h"
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Type1;
/* Finds the last occurrences of two keys and merges their counts. */
void func_004D6E48(Type1 *a, s32 b, s32 c, s32 n)
{
    s32 x = -1;
    s32 y = -1;
    s32 i;
    for (i = 0; i < n; i++) {
        s32 value = a[i].f0;
        if (value == b)
            x = i;
        if (value == c)
            y = i;
    }
    if (x >= 0 && y >= 0) {
        a[y].f4 += a[x].f4;
        a[x].f8 = 0;
    }
}
