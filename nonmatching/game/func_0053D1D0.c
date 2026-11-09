/* Not matching yet: BYTES 4/636 (tools/try_func.py func_0053D1D0 --diff). Not part of the build. */
/* cflags: -mno-split-addresses */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct Type2 {
    char pad0[0x34];
    u16 f34;
    char pad36[0x98 - 0x36];
    s32 f98;
} Type2;

typedef struct Type3 {
    char pad0[0xB8];
    Type2 *fB8;
    s16 fBC;
    u8 fBE;
} Type3;

struct Type1;

typedef struct Type4 {
    char pad0[0x3C];
    s32 (*f3C)(struct Type1 *, s32, s32, s32, s32);
    char pad40[0x4C - 0x40];
    s32 (*f4C)(struct Type1 *);
} Type4;

typedef struct Type1 {
    char pad0[0x14];
    Type4 *f14;
    char pad18[0xA0 - 0x18];
    u128 fA0;
    char padB0[0x2662 - 0xB0];
    u8 f2662;
    char pad2663[0x266D - 0x2663];
    u8 f266D;
    char pad266E[0x2EF0 - 0x266E];
    Type2 *f2EF0;
    void *f2EF4;
    s32 f2EF8;
    char pad2EFC[0x2F00 - 0x2EFC];
    s32 f2F00;
    char pad2F04[0x2F14 - 0x2F04];
    s32 f2F14;
    s32 f2F18;
} Type1;

typedef struct Type0 {
    char pad0[0x2B0];
    Type3 *f2B0;
    char pad2B4[0x2B8 - 0x2B4];
    Type1 *f2B8;
    char pad2BC[0x2D8 - 0x2BC];
    s32 f2D8;
    char pad2DC[0x2FC - 0x2DC];
    u8 f2FC;
    char pad2FD[0x328 - 0x2FD];
    Type1 *f328;
} Type0;

extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_00221280[];

void func_00438F58(s32 arg0, s32 arg1);
void func_0044E060(void *arg0, Type1 *arg1, u128 arg2, s32 arg3);
void func_0045D950(s32 arg0, s32 arg1, s32 arg2);
void func_00496E78(s32 arg0, s32 arg1, s32 arg2);

void func_0053D1D0(Type0 *arg0, Type1 *arg1) {
    s32 flags;

    if (arg0->f328 != arg1) {
        if (D_0021EDD4 == 1 || arg0->f2B0->fBC != 0x2054) {
            func_0044E060(D_00221280, arg1, arg1->fA0, 0);
        }
        if (D_0021EDD4 == 1 && arg0->f2B0->fBC == 0x2054) {
            func_0044E060(D_00221280, arg1, arg1->fA0, 1);
        }
    }
    if (arg1->f266D != 0) {
        func_00438F58(0, arg1->f2F00);
        func_00496E78(arg1->f14->f4C(arg1), 1, 0);
        if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
            func_00496E78(arg1->f14->f4C(arg1), 8, 0);
        }
    }
    arg0->f2B8 = arg1;
    arg0->f328 = 0;
    arg0->f2D8 &= 0xFFFFFBD1;
    arg0->f2B0->fB8 = arg1->f2EF0;
    arg1->f2F18 = 5;
    arg1->f2EF4 = arg0;
    arg1->f2EF8 = 0;
    arg1->f14->f3C(arg1, 0x31, 1, 0, 1);
    arg0->f2FC = 1;
    if (arg0->f2D8 & 0x04800000) {
        arg1->f2EF0->f34 |= 0x800;
    }
    arg1->f2EF0->f98 = 0;
    if (!(arg0->f2D8 & 0x800000) && (arg1->f266D != 0 || !(arg0->f2D8 & 0x04000000))) {
        arg1->f2662 = 1;
    }
    if (arg1->f2F14 == 0) {
        arg0->f2B0->fBE |= 0x10;
        arg0->f2B0->fBE &= ~8;
    } else if (arg1->f2F14 == 1) {
        arg0->f2B0->fBE |= 8;
        arg0->f2B0->fBE &= ~0x10;
    }
    if (D_0021EDD4 == 1 && arg1->f266D != 0) {
        func_0045D950(0x2993, 0x30A, 2);
    }
    flags = arg0->f2D8;
    if (arg1->f266D == 0) {
        flags |= 0x20;
    } else {
        flags |= 4;
    }
    arg0->f2D8 = flags;
}
