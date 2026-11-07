/* Not matching yet: BYTES 10/412 (tools/try_func.py func_005133C8 --diff). Not part of the build. */
/* cflags: -ffast-math */
#include "common.h"

typedef unsigned int u128 __attribute__((mode(TI)));

extern void func_00453718(void *, const void *, u32);
extern void func_0046C0D8(void *, s32, void *, f32, f32);
extern void func_004706F0(void *);
extern void func_00513278(char *p);
extern void func_005132F8(char *p);
extern s32 func_00515740(char *p);
extern void func_005241C0(char *p, void *, void *, f32);


static inline f32 fmax0(f32 a, f32 b)
{
    return b > a ? b : a;
}

void func_005133C8(char *p)
{
    u128 v;
    f32 h;
    f32 m;
    char *o;
    char *c;

    *(u8 *)(*(char **)(p + 0x2EF0) + 0x2C) = 0xFF;
    *(u128 *)(*(char **)(p + 0x2EF0) + 0x10) = *(u128 *)(p + 0xA0);
    func_00513278(p);
    *(u128 *)(*(char **)(p + 0x2EF0) + 0xF0) = *(u128 *)(p + 0xB0);
    func_005132F8(p);
    func_00453718(*(char **)(p + 0x2EF0) + 0xC0, p + 0x20, 0x30);
    *(u8 *)(*(char **)(p + 0x2EF0) + 0x55) &= 0x7F;
    *(u8 *)(*(char **)(p + 0x2EF0) + 0x55) &= 0xDF;
    func_004706F0(*(char **)(p + 0x2EF0));
    o = *(char **)(p + 0x2EF0);
    c = *(char **)(o + 0x24);
    if (c == 0 || *(u8 *)(c + 6) != 0) {
        *(u8 *)(o + 0x66) = 0x10;
    } else {
        *(u8 *)(*(char **)(p + 0x2EF0) + 0x66) = *(u8 *)(c + 6) + 0x10;
    }
    if (*(s16 *)(p + 0x3A0) == 0 && *(s32 *)(*(char **)(p + 0x2EF0) + 0x98) != 0) {
        m = 0.05f;
        v = *(u128 *)(p + 0xA0);
        func_005241C0(p, &v, &v, -*(f32 *)(p + 0x1F4));
        func_0046C0D8(*(char **)(p + 0x2EF0), 0, &v, *(f32 *)(p + 0x204),
                      fmax0(*(f32 *)(p + 0x1F0) - *(f32 *)(p + 0x1F4), m));
        h = *(f32 *)(p + 0x204) + m;
        if (*(s32 *)(p + 0x25D4) == 4) {
            h += 0.15f;
        }
        if (func_00515740(p) != 0) {
            h = *(f32 *)(p + 0x1F4);
        }
        v = *(u128 *)(p + 0xA0);
        func_005241C0(p, &v, &v, -h);
        func_0046C0D8(*(char **)(p + 0x2EF0), 1, &v, *(f32 *)(p + 0x204),
                      fmax0(*(f32 *)(p + 0x1F0) - h, m));
    }
}
