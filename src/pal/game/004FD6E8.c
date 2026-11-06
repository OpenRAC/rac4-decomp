#include "common.h"

/* Increments the counter for a key in the sentinel-terminated table. */
typedef struct {
    s32 f0, f4;
} Type1;
extern Type1 D_00172060[];
void func_004FD6E8(s32 key)
{
    s32 i = 0;
    while (D_00172060[i].f0 != -1 && D_00172060[i].f0 != key)
        i++;
    if (D_00172060[i].f0 != -1)
        D_00172060[i].f4++;
}
