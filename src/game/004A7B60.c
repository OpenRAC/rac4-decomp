#include "common.h"

extern s32 func_004908D0();
extern u8 D_003D7D88[];

s32 func_004A7B60(u8 *arg0, s32 arg1) {
    s32 v;
    s32 t;

    if (*(s32 *)(arg0 + 0x2EE0) != 0)
        return 0;
    v = func_004908D0(0x10, *(s32 *)(arg0 + 0x2F10));
    if (v & 0x10) {
        t = *(s32 *)(D_003D7D88 + *(s32 *)(arg0 + 0x2F10) * 0x1C);
        if (t != 0 && t != 0x12)
            v &= ~0x10;
    }
    t = *(s32 *)(arg0 + 0x2F00);
    return ((arg1 != 0 ? ((s32 *)t)[0x1A4 / 4] : ((s32 *)t)[0x1A0 / 4]) & v) != 0;
}
