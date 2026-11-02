#include "common.h"

extern u8 D_00267000[];
extern void *D_00267040[];
extern char D_00266C00[];

/* Reserve a free entry for an eligible object and return its state record. */
void *func_0046F8C0(u8 *object)
{
    s32 i;
    if (!object[0x31] || (object[0x20] & 0x80))
        return 0;
    for (i = 0; i < 32; i++) {
        u8 *p = D_00267000 + i;
        if (!*p) {
            *p = 1;
            D_00267040[i] = object;
            return D_00266C00 + (i << 5);
        }
    }
    return 0;
}
