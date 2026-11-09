/* cflags: -ffast-math */
#include "common.h"

typedef struct Obj {
    u8 pad0[0xB8];
    u8 fB8[0x17A0 - 0xB8];
    f32 f17A0;
    u8 f17A4[4];
    f32 f17A8;
    u8 pad17AC[0x1AE0 - 0x17AC];
    s32 f1AE0;
    u8 pad1AE4[0x2318 - 0x1AE4];
    s32 f2318;
    u8 pad231C[0x25C4 - 0x231C];
    f32 f25C4;
    u8 pad25C8[4];
    s32 f25CC;
    u8 pad25D0[0x2659 - 0x25D0];
    u8 f2659;
    u8 f265A;
    u8 pad265B[0x2F00 - 0x265B];
    s32 f2F00;
} Obj;

extern f32 func_00475D98(void *, void *, f32, f32, f32, f32, s32);
extern s32 func_0048F878(s32, s32, s32, s32);
extern void func_0051BA68(Obj *, f32, f32, f32, s32);
extern f32 D_0021DDEC;
extern f32 D_0021DDF4;

void func_0051BB40(Obj *arg0, s32 arg1, f32 a, f32 b, f32 c) {
    f32 t0;
    f32 t1;

    if (arg0->f25CC != 0x3F && arg0->f1AE0 != 0
        && (arg0->f265A != 0 || func_0048F878(0x28, 2, 0, arg0->f2F00) != 0)
        && arg0->f2318 != 1) {
        t0 = D_0021DDEC * 0.2f;
        t1 = D_0021DDF4 * 52.359879f;
        t0 = t0 * arg0->f25C4;
        t1 = t1 * arg0->f25C4;
        a = (t0 > a) ? t0 : a;
        c = (t1 > c) ? t1 : c;
    }
    if (arg0->f2659 != 0) {
        func_0051BA68(arg0, a, b, c, arg1);
        return;
    }
    arg0->f17A8 = func_00475D98(arg0->fB8, arg0->f17A4, arg0->f17A0, a, b, c, arg1);
}
