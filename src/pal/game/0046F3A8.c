#include "common.h"

extern void func_0046A080(void *, s32, s32);
extern void func_0046A0C0(void);
extern void func_0046E7D8(f32, f32);

void func_0046F3A8(u8 *arg0, f32 t, f32 u)
{
    s32 i;
    f32 frac;
    s32 next;
    u8 *base;
    s32 count;
    s32 off;
    u8 *a;
    u8 *b;

    i = (s32)t;
    frac = t - (f32)i;
    next = i + 1;
    base = *(u8 **)(arg0 + 0x1C);
    off = base[1];
    count = base[2];
    if (next == arg0[0x10]) {
        next = 0;
    }
    a = base + (off + i * count) * 16;
    b = base + (next * count + off) * 16;
    if (off != 0) {
        func_0046A080(base, off, 0x2000);
        func_0046A0C0();
    }
    if (count != 0) {
        func_0046A080(a, count, 0x3000);
        func_0046A0C0();
        func_0046A080(b, count, 0x3800);
        func_0046A0C0();
    }
    func_0046E7D8(frac, u * u * (3.0f - (u + u)));
}
