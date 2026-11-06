#include "common.h"

extern s32 func_00469C40(u8 *, s32);
extern u8 *D_0023AB20[];
extern s32 D_003DBF10[];

void func_004F3390(s32 a0, s32 *a1, s32 a2)
{
    s32 valid = a0 < 36;
    u8 *base = D_0023AB20[0];
    s32 delta = *(s32 *)(base + 0xC);
    u8 *p = base + delta;
    s32 count = *(s32 *)p;
    s32 **entries = (s32 **)(p + 0x10);
    s32 mapped;
    s32 offset;

    if (valid) {
        mapped = D_003DBF10[a0];
        if (mapped != -1 && mapped < count && entries[mapped] != 0) {
            goto selected;
        }
    }
    a0 = 0;

selected:
    offset = D_003DBF10[a0];
    *a1 = func_00469C40(p + (s32)entries[offset], a2);
}
