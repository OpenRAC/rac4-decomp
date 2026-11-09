/* Not matching yet: BYTES 64/848 (tools/try_func.py func_00526090 --diff). Not part of the build. */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct Type4 {
    char _p0[0x2B0];
    s32 f2B0;
} Type4;

typedef struct Type3 {
    char _p0[0x20];
    u8 f20;
    char _p21[0xAC - 0x21];
    Type4 *fAC;
} Type3;

typedef struct Type5 {
    char _p0[0x27B];
    u8 f27B;
} Type5;

typedef struct Type6 {
    char _p0[0x3C];
    u8 f3C;
} Type6;

struct Type1;

typedef struct Type2 {
    char _p0[0x38];
    void (*f38)(struct Type1 *);
    void (*f3C)(struct Type1 *, s32, s32, s32, s32);
    char _p40[0x4C - 0x40];
    s32 (*f4C)(struct Type1 *);
} Type2;

typedef struct Type1 {
    char _p0[0x14];
    Type2 *f14;
    char _p18[0xA0 - 0x18];
    u128 fA0;
    s32 fB0;
    s32 fB4;
    char _pB8[0x1784 - 0xB8];
    s32 f1784;
    char _p1788[0x25D4 - 0x1788];
    s32 f25D4;
    char _p25D8[0x2659 - 0x25D8];
    u8 f2659;
    char _p265A[0x2662 - 0x265A];
    u8 f2662;
    char _p2663[0x266D - 0x2663];
    u8 f266D;
    char _p266E[0x2DDC - 0x266E];
    s32 f2DDC;
    char _p2DE0[0x2DF0 - 0x2DE0];
    Type3 *f2DF0;
    char _p2DF4[0x2E20 - 0x2DF4];
    f32 f2E20;
    char _p2E24[0x2EF0 - 0x2E24];
    s32 f2EF0;
    char _p2EF4[0x2EFC - 0x2EF4];
    Type5 *f2EFC;
    char _p2F00[0x2F10 - 0x2F00];
    s32 f2F10;
} Type1;

extern s32 D_0021EDD4;

extern Type3 *func_0042E3B0(s32 a, s32 b, s32 c);
extern void func_0042ED20(Type3 *a, s32 b);
extern void func_0043D780(s32 a, s32 b);
extern void func_0045DB78(s32 a, s32 b, s32 c, s32 d);
extern Type6 *func_00476690(s32 a);
extern void func_0051A638(Type1 *a);
extern void func_0051A820(Type1 *a);
extern void func_005241C0(Type1 *a, u128 *b, u128 *c, f32 d);
extern void func_0053CB20(s32 *a, u8 *b, s32 n);

void func_00526090(Type1 *arg0, s32 *arg1)
{
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 t;
    u128 saved;
    u32 kind;
    s32 mode;
    Type3 *p;
    Type3 *r;
    Type4 *q;
    Type6 *obj;
    s32 v;

    kind = *arg1 & 0xF;
    switch (kind) {
    case 5:
    case 7:
    case 8:
    case 9:
        if (arg0->f25D4 == 0x14) {
            return;
        }
        if (arg0->f2DF0 != NULL) {
            return;
        }
        func_0053CB20(arg1, &b0, 1);
        func_0053CB20(arg1, &b1, 1);
        func_00476690(arg0->f2EF0)->f3C = 3;
        if (arg0->f266D != 0) {
            saved = arg0->fA0;
            func_005241C0(arg0, &arg0->fA0, &arg0->fA0, -0.7f);
            func_0051A820(arg0);
            arg0->fA0 = saved;
        }
        func_0051A638(arg0);
        arg0->f14->f3C(arg0, 0x31, 1, 1, 1);
        arg0->f2EFC->f27B = 1;
        arg0->f2659 = 0;
        arg0->f2DDC = 0;
        if (arg0->f266D != 0) {
            func_0043D780(arg0->f14->f4C(arg0), 1);
        }
        arg0->f2662 = 1;
        arg0->fB0 = 0;
        arg0->fB4 = 0;
        arg0->f1784 = 0;
        t = b1 * 60;
        arg0->f14->f38(arg0);
        kind = *arg1 & 0xF;
        if (kind == 5) {
            if (D_0021EDD4 == 1 && arg0->f266D != 0) {
                func_0045DB78(0x2992, 0x309, 3, 2);
            }
            p = func_0042E3B0(arg0->f2EF0, t, 1);
        } else if (kind == 8) {
            if (D_0021EDD4 == 1 && arg0->f266D != 0) {
                func_0045DB78(0x2992, 0x309, 3, 2);
            }
            p = func_0042E3B0(arg0->f2EF0, t, 0);
        } else if (kind == 9) {
            if (D_0021EDD4 == 1 && arg0->f266D != 0) {
                func_0045DB78(0x2992, 0x309, 3, 2);
            }
            p = func_0042E3B0(arg0->f2EF0, t, 3);
        } else {
            if (D_0021EDD4 == 1 && arg0->f266D != 0) {
                func_0045DB78(0x2992, 0x309, 3, 2);
            }
            p = func_0042E3B0(arg0->f2EF0, t, 2);
        }
        arg0->f2DF0 = p;
        func_0042ED20(p, arg0->f2F10);
        arg0->f2E20 = 1.0f;
        obj = func_00476690(arg0->f2EF0);
        if (obj != NULL) {
            obj->f3C = 3;
        }
        break;
    case 6:
        func_0053CB20(arg1, &b2, 1);
        func_0053CB20(arg1, &b3, 1);
        obj = func_00476690(arg0->f2EF0);
        if (obj != NULL) {
            obj->f3C = 1;
        }
        p = arg0->f2DF0;
        if (p != NULL && p->f20 != 0xFE) {
            if (p->f20 == 0xFD) {
                arg0->f2DF0 = NULL;
                return;
            }
            q = p->fAC;
            if (q != NULL) {
                if (b2 != 0) {
                    q->f2B0 = 2;
                } else if (b3 != 0) {
                    q->f2B0 = 3;
                } else {
                    q->f2B0 = 1;
                }
            }
        }
        arg0->f2DF0 = NULL;
        break;
    }
}
