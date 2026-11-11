#include "common.h"
/* Ported from rac3-decomp's func_L01_0046FA88 (src/levels/shared/L01_0046A938.c, GPL-3.0), the same code in both games. */

typedef struct {
    f32 target;
    f32 base;
    s32 b;
    s32 a;
    f32 scale;
} Sub;
typedef struct {
    char pad0[0x4];
    s32 result;
    char pad8[0xA - 0x8];
    s16 timer;
    f32 out;
    char vec[0x20 - 0x10];
    Sub sub;
} Obj;
extern f32 func_00453940(f32);
extern s32 func_00453508(s16 *);
extern void func_00490AC8(Obj *);
void func_L00_00615D58(Obj *o) {
    if (o != 0) {
        Sub *s = &o->sub;
        if (func_00453508((s16 *)&s->base) != 0) {
            func_00490AC8(o);
        } else {
            f32 ang = (f32)*(s16 *)((u8 *)s + 4) / (f32)*(s16 *)((u8 *)s + 6) * 6.2831855f;
            f32 x;
            s32 c;
            x = (f32)s->a * func_00453940(ang);
            c = o->result;
            o->result = (c & 0xFFFFFF) + ((s32)__builtin_fabsf(x) << 24);
        }
    }
}
