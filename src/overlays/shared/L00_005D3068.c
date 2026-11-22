#include "common.h"

extern void func_004537D0(s32, s32, s32);
extern u8 *D_002220D0;
extern s32 D_002220D4;

void func_L00_005D3068(s32 arg0, s32 arg1, s32 *arg2) {
    s32 i = 0;

    for (; i < D_002220D4; i++) {
        u8 *p = (u8 *)((i << 5) + (u32)D_002220D0);
        s32 idx = *(s32 *)(p + 0x1C);
        if (idx < 0) {
            *(s32 *)(p + 0x1C) = 0;
        } else {
            s32 *e = (s32 *)((idx << 3) + arg0);
            s32 size = e[1];
            s32 off = e[0];
            *(s32 *)(p + 0x1C) = *arg2;
            func_004537D0(*arg2, arg1 + off, size);
            e[0] = *arg2;
            *arg2 += size;
        }
    }
}
