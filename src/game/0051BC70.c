/* cflags: -ffast-math */
#include "common.h"

typedef struct Obj {
    u8 pad0[0x1C8F];
    u8 f1C8F;
    u8 pad1C90[0x2314 - 0x1C90];
    s32 f2314;
    s32 f2318;
    u8 pad231C[0x25C4 - 0x231C];
    f32 f25C4;
    u8 pad25C8[0x265A - 0x25C8];
    u8 f265A;
    u8 pad265B[0x2E08 - 0x265B];
    f32 f2E08;
} Obj;

extern void func_0051BB40(Obj *arg0, s32 arg1, f32 a, f32 b, f32 c);
extern f32 D_0021DDEC;
extern f32 D_0021DDF4;

static inline s32 func_0051BC70_state(Obj *arg0) {
    if (arg0->f2314 == 2) {
        return arg0->f2318;
    }
    return -1;
}

void func_0051BC70(Obj *arg0) {
    f32 a;
    f32 b;
    f32 c;
    s32 state;
    f32 s;
    f32 tb;

    s = arg0->f2E08;
    if (s == 1.0f) {
        f32 t0;

        t0 = D_0021DDEC * 0.022f;
        a = t0 * arg0->f25C4;
    } else {
        f32 t0;
        f32 t1;
        f32 t2;
        f32 hi;
        f32 lo;

        t0 = D_0021DDEC * 0.02f;
        t1 = D_0021DDEC * 0.022f;
        t2 = D_0021DDEC * 0.01f;
        t0 = t0 * arg0->f25C4;
        hi = t1 * arg0->f25C4;
        lo = t2 * arg0->f25C4;
        a = t0 * s;
        a = (hi < a) ? hi : a;
        a = (lo > a) ? lo : a;
    }
    if (arg0->f2E08 == 1.0f) {
        f32 t0;

        t0 = D_0021DDF4 * 5.5850534f;
        c = t0 * arg0->f25C4;
    } else {
        f32 t0;
        f32 t1;
        f32 t2;
        f32 hi;
        f32 lo;

        t0 = D_0021DDF4 * 3.8397243f;
        t1 = D_0021DDF4 * 5.5850534f;
        t2 = D_0021DDF4 * 1.9198622f;
        t0 = t0 * arg0->f25C4;
        hi = t1 * arg0->f25C4;
        lo = t2 * arg0->f25C4;
        c = t0 * s;
        c = (hi < c) ? hi : c;
        c = (lo > c) ? lo : c;
    }
    tb = D_0021DDEC * 0.27f;
    b = tb * arg0->f25C4;
    if (arg0->f1C8F != 0) {
        f32 t0;
        f32 t1;

        t0 = D_0021DDEC * 0.035f;
        t1 = D_0021DDF4 * 11.693706f;
        a = t0 * arg0->f25C4;
        c = t1 * arg0->f25C4;
    }
    state = func_0051BC70_state(arg0);
    if (state == 2 && arg0->f265A != 0 && arg0->f1C8F == 0) {
        if (s > 0.95f) {
            f32 t0;
            f32 t1;
            f32 t2;

            t0 = D_0021DDEC * 0.017f;
            t1 = D_0021DDEC * 0.18f;
            t2 = D_0021DDF4 * 8.726646f;
            a = t0 * arg0->f25C4;
            b = t1 * arg0->f25C4;
            c = t2 * arg0->f25C4;
        } else {
            f32 t0;
            f32 t1;
            f32 t2;

            t0 = D_0021DDEC * 0.009f;
            t2 = D_0021DDF4 * 4.712389f;
            t1 = D_0021DDEC * 0.15f;
            t0 = t0 * arg0->f25C4;
            t2 = t2 * arg0->f25C4;
            b = t1 * arg0->f25C4;
            a = t0 * s;
            c = t2 * s;
        }
    }
    func_0051BB40(arg0, 0, a, b, c);
}
