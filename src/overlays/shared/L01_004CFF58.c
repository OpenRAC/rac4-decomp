#include "common.h"

extern s32 D_00172378[];

// Decides whether object arg0 is moving toward its target and within range.
s32 func_L01_004CFF58(void *arg0) {
    u8 *obj;
    s32 r;
    s32 n;
    s32 m;

    obj = *(u8 **)((u8 *)arg0 + 0xAC);
    r = 1;
    if ((((*(u64 *)((u8 *)arg0 + 0x30)) & ((u64)0x8208 << 29)) != ((u64)0x8200 << 23)) || (*(s32 *)((u8 *)arg0 + 0x98) != 0)) {
        r = 0;
    }
    if (*(f32 *)(obj + 0x50) > 0.0f) {
        r = 0;
    }
    n = *(s32 *)(obj + 0x23C);
    if (n > 0) {
        m = *(s32 *)(obj + 0x240);
        if ((f32)m > 0.0f) {
            if (n >= D_00172378[0] - m) {
                r = 0;
            }
        } else {
            r = 0;
        }
    } else {
        r = 0;
    }
    return r;
}
