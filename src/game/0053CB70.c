#include "common.h"
typedef struct {
    u32 f0;
    u32 f4;
    char p8[0x44];
    u32 f4C;
} Type1;
typedef struct {
    u8 pad[0x218];
    u32 tick;
} Profile00172160;
extern Profile00172160 D_00172160;

/* Stores the tick origin and deadline, encoding the elapsed duration. */
void func_0053CB70(Type1 *a, s32 b, s32 c)
{
    u32 p = D_00172160.tick;
    a->f4 = p;
    if (c > 0)
        a->f0 = (a->f0 & 0x3FFF) |
                ((D_00172160.tick + b + c - p) << 14);
    else
        a->f0 &= 0x3FFF;
    a->f4C = D_00172160.tick + b;
}
