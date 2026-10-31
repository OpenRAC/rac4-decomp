#include "common.h"

extern s32 func_004FC518(s32 arg0);
extern u8 D_322EA4[];

// Picks the 0x18-byte entry for arg0 (or for the value at +0x54 when arg0 is negative) and returns whether func_004FC518 reaches its threshold at +8.
s32 func_004DACC0(s32 arg0) {
    u8 *b;
    u8 *e;
    u8 *s0;
    s32 r;

    b = D_322EA4;
    if (arg0 >= 0) {
        e = (u8 *)*(s32 *)(b + 0x34) + arg0 * 0x18;
    } else {
        arg0 = *(s32 *)(b + 0x54);
        e = 0;
        if (arg0 >= 0) e = (u8 *)*(s32 *)(b + 0x34) + arg0 * 0x18;
    }
    s0 = *(u8 **)(e + 8);
    r = 0;
    if (*(s32 *)s0 != 0) {
        r = func_004FC518(arg0) >= *(s32 *)(s0 + 8);
    }
    return r;
}
