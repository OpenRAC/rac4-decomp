/* cflags: -ffast-math */
#include "common.h"

extern void func_00497908(s32 arg0, s32 arg1);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_00505B20(void);
extern u8 D_00307B58[];

void func_004A46A8(void) {
    s32 id;
    s32 off;
    u8 *base;
    u8 *q;
    f32 *p;
    f32 v;

    id = func_00505B20();
    off = id * 0xEC;
    base = D_00307B58;
    q = base + 0xD0;
    p = (f32 *)(q + off);
    *p -= 0.04f;
    v = *p;
    v = v > 1.0f ? 1.0f : v;
    v = v < 0.0f ? 0.0f : v;
    func_00505410(0xE0001, v);
    func_00505410(0xE0002, v);
    func_00505410(0xE0003, v);
    if (*p <= 0.0f) {
        *(s32 *)(base + off) &= ~1;
        func_00497908(id, 0x40);
    }
}
