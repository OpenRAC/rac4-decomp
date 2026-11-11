/* cflags: -ffast-math */
#include "common.h"

extern f32 func_00453B10(f32, f32);
extern s32 func_005049B8(s32 handle, u32 value);
extern void func_00504F68(s32, s32);
extern void func_00505328(s32, s32);
extern s32 func_00505B20(void);
extern u8 D_00307B58[];

void func_004A49E0(void) {
    s32 off;
    u8 *base;
    f32 *p;
    f32 *q;
    s32 a;
    u8 *t;
    u8 *t2;
    u8 *c;
    s32 *cnt;

    off = func_00505B20() * 0xEC;
    base = D_00307B58;
    t = base + 0xDC;
    p = (f32 *)(t + off);
    c = base + 8;
    cnt = (s32 *)(c + off);
    t2 = base + 0xE0;
    q = (f32 *)(t2 + off);
    *p -= 0.05f;
    (*cnt)++;
    *q = func_00453B10(*q, 0.1f);
    if (*p <= 0.0f) {
        func_00504F68(0xE0009, 0);
        func_00504F68(0xE000A, 0);
        func_00504F68(0xE000B, 0);
        *(s32 *)(base + off) &= ~8;
    } else if (*p < 1.0f) {
        a = (s32)(*p * 64.0f) << 24;
        func_00505328(0xE0009, ((s32)(*p * 128.0f) << 24) | 0xD0D0D0);
        func_005049B8(0xE0009, a);
        func_00505328(0xE000A, ((s32)(*p * 128.0f) << 24) | 0x20F0F0);
        func_005049B8(0xE000A, a);
        func_00505328(0xE000B, ((s32)(*p * 128.0f) << 24) | 0x20F0F0);
        func_005049B8(0xE000B, a);
    }
}
