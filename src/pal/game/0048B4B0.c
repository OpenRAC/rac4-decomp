#include "common.h"

typedef struct Type1 {
    u32 f0;
    char pad4[3];
    u8 f7;
    char pad8[2];
    u8 fA;
    char padB[9];
    s32 f14;
    char pad18[8];
    f32 f20, f24;
    s32 f28, f2C;
} Type1;
/* Initialize the record fields. */
void func_0048B4B0(s32 unused, Type1 *p)
{
    p->f20 = 1.0f;
    p->f24 = 1.0f;
    p->f28 = 0;
    p->f2C = 0;
    p->f7 = 0;
    p->f0 = 0xffffffffu;
    p->fA = 0;
    p->f14 = 0;
}
