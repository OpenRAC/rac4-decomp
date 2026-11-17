/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct { u8 b[13]; } Type13;
typedef struct { u8 b[32]; } Type32;
typedef struct { Type13 a; Type32 b; Type32 c; u8 pad[19]; } Type77;
typedef struct { char pad[0x10]; s32 f10; u8 f14[1]; } Type5;
typedef struct { char pad[0x104]; s32 f104; s32 f108; } Type4;
typedef struct { char pad[0x44]; Type32 f44; Type32 f64; } Type6;
typedef struct { char pad[0x54]; Type6 *f54; char pad2[0x58]; Type5 *fB0; char pad3[0x28]; Type4 *fDC; } Type1;
extern Type13 D_004AF960[];
extern s32 func_L00_0052B040(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4, s32 a5, u8 *a6, u8 *a7, s32 a8);

/* Builds a 77-byte key from a fixed prefix and two 32-byte object fields, then derives two outputs from it. */
s32 func_L00_0052B150(Type1 *arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    Type77 buf;
    Type5 *k;
    Type4 *d;
    s32 r;

    buf.a = D_004AF960[0];
    buf.b = arg0->f54->f44;
    buf.c = arg0->f54->f64;
    k = arg0->fB0;
    d = arg0->fDC;
    r = func_L00_0052B040(d->f104, d->f108, (s32)&buf, 0x4D, k->f14, k->f10, arg1, arg2, arg3);
    return r;
}
