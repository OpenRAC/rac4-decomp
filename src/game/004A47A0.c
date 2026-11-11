/* cflags: -ffast-math */
#include "common.h"

extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_00505B20(void);
extern u8 D_00307B58[];

/* Fades out a per-player value by 0.04, clamps it to [0,1], applies it to three channels, clears flag 2 when it reaches 0. */
void func_004A47A0(void) {
    s32 off;
    u8 *base;
    u8 *q;
    f32 *p;
    f32 v;

    off = func_00505B20() * 0xEC;
    base = D_00307B58;
    q = base + 0xD4;
    p = (f32 *)(q + off);
    *p -= 0.04f;
    v = *p;
    v = v > 1.0f ? 1.0f : v;
    v = v < 0.0f ? 0.0f : v;
    func_00505410(0xE0004, v);
    func_00505410(0xE0005, v);
    func_00505410(0xE0006, v);
    if (*p <= 0.0f) {
        *(s32 *)(base + off) &= ~2;
    }
}
