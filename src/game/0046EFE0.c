#include "common.h"

extern u8 D_00266F00[];
extern void *D_00266F40[];
extern char D_00266B00[];

/* Reserve a free entry for an eligible object and return its state record. */
void *func_0046EFE0(u8 *object)
{
    s32 i;
    if (!object[0x31] || (object[0x20] & 0x80))
        return 0;
    for (i = 0; i < 32; i++) {
        u8 *p = D_00266F00 + i;
        if (!*p) {
            *p = 1;
            D_00266F40[i] = object;
            return D_00266B00 + (i << 5);
        }
    }
    return 0;
}
