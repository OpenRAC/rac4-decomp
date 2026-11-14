#include "common.h"

extern void func_L00_00717D98(s32 a0);
extern u8 D_1EE600[];

// Frees each used slot of the four at +0x268 whose record in D_1EE600 is not busy, clearing its flags.
void func_L00_00747798(u8 *arg0) {
    s32 *p = (s32 *)(arg0 + 0x268);
    u32 i = 1;
    u8 *slot = arg0 + 0x294;
    u8 *tbl = (u8 *)D_1EE600;
    s32 stride = 0x5C0;
    do {
        s32 v = p[0];
        if (~v != 0 && *(s32 *)(tbl + v * stride + 0x19C) == 0) {
            func_L00_00717D98(i);
            slot[i] = 0;
            p[0] = -1;
            p[4] = 0;
            if (arg0[0x299] != 0) {
                p[8] = 0;
            }
        }
        i++;
        p++;
    } while (i < 4);
}
