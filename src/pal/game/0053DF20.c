#include "common.h"
typedef struct {
    u32 f0;
    u32 f4;
    char p8[0x44];
    u32 f4C;
} Type1;
typedef struct {
    char p0[0x218];
    u32 f218;
} Type2;
extern Type2 D_001721E0[];

/* Stores the tick origin and deadline, encoding the elapsed duration. */
void func_0053DF20(Type1 *a, s32 b, s32 c)
{
    u32 p = D_001721E0[0].f218;
    a->f4 = p;
    if (c > 0)
        a->f0 = (a->f0 & 0x3FFF) |
                ((D_001721E0[0].f218 + b + c - p) << 14);
    else
        a->f0 &= 0x3FFF;
    a->f4C = D_001721E0[0].f218 + b;
}
