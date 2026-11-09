#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xB8];
    f32 fB8;
    char _pBC[0x538];
    s16 f5F4;
    u8 f5F6;
    u8 f5F7;
    char _p5F8[0x1198];
    char f1790[0x10];
    f32 f17A0;
    char _p17A4[0x33C];
    s32 f1AE0;
    char _p1AE4[0xAE8];
    s32 f25CC;
    char _p25D0[0x89];
    u8 f2659;
    char _p265A[0x8A6];
    s32 f2F00;
};

f32 func_00453B58(f32 to, f32 from);
f32 func_00453BF8(f32, f32);
s32 func_0048F878(s32, s32, s32, s32);
s32 func_00515718(Type1 *);
void func_0051B168(void *, s32, f32);
f32 func_0051FC38(Type1 *, void *, s32);

s32 func_005210B0(Type1 *p)
{
    s32 r = 2;
    s32 v;
    u8 m;
    f32 a;

    if (p->f5F4 == 0) {
        v = p->f1AE0;
        if (v != 1 || func_0048F878(0x28, 2, 0, p->f2F00) == 0 ||
            func_00515718(p) == v || func_00515718(p) == 0xF) {
            goto calc;
        }
    }
    if (p->f25CC != 0x10) {
        m = p->f5F7;
        if (m == 0) {
            r = 0;
        } else if (m == 3) {
            r = -1;
        } else {
            r = m == 2 ? 2 : 1;
        }
        return r;
    }
calc:
    func_0051B168(p, 0, 1.0f);
    if (p->f2659 != 0) {
        a = func_0051FC38(p, p->f1790, 0);
    } else {
        a = func_00453B58(p->f17A0, p->fB8);
    }
    if (func_00453BF8(a, 3.1415927f) < 0.7853982f) {
        r = -1;
    } else if (func_00453BF8(a, -1.5707964f) < 0.7853982f) {
        r = 1;
    } else if (func_00453BF8(a, 1.5707964f) < 0.7853982f) {
        r = 0;
    }
    return r;
}
