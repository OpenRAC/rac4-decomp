#include "common.h"

typedef struct Type1 {
    char _p0[0x10];
    s32 f10;
    s32 f14;
    char _p18[0x64 - 0x18];
    u8 *f64;
} Type1;
extern void func_0011A370(u8 *, u8 *, s32);
extern void func_0011A9EC(void *, void *);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_01ED7130();
extern u16 D_00221928[];
extern Type1 *D_002233A4;

// Builds a record and submits it, returning 1 unless too long or failed.
s32 func_L00_0077CD30(s32 unused, s32 arg0, s32 arg1, u8 *arg2, s32 arg4) {
    u8 buf[0x1C0];
    s32 r = 1;
    Type1 *g = D_002233A4;
    u8 *f = g->f64;

    *(u16 *)buf = D_00221928[0];
    func_0011A9EC(buf + 0x15, f);
    *(s32 *)(buf + 0x28) = arg0;
    *(s32 *)(buf + 0x2C) = arg1;
    if (arg4 > 0x190) {
        arg4 = 0x190;
        r = 0;
    }
    func_0011A370(buf + 0x30, arg2, arg4);
    func_0015B548(func_01ED7130(buf));
    if (func_0015B558() != 0) {
        g->f10 = 0x49;
        if (g->f14 == 0) {
            g->f14 = 0x49;
        }
        r = 0;
    }
    return r;
}
