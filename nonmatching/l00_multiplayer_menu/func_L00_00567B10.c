/* Not matching yet: BYTES 4/780 (tools/try_func.py func_L00_00567B10 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    char _p0[0x14];
    char f14[0x40];
    s32 f54;
} Type2;
typedef struct Type1 {
    struct Type1 *f0;
    struct Type1 *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    char _p14[0x54 - 0x14];
    struct Type1 *f54;
    char _p58[0x6C - 0x58];
    s32 f6C;
} Type1;

extern Type1 *D_004A9BA0[];
extern Type1 *D_004A9BA4[];

s32 func_01E9BB28(void *, s32, s32, s32);
s32 func_01E9BD30(void *, s32, s32, s32, void *, s32);
void func_L00_00566910(void *);
s32 func_L00_00566950(void);
void func_L00_005669C0(void);
Type2 *func_L00_005669E0(s32 arg0);
s32 func_L00_00566BA0(void *, s32);
Type1 *func_L00_00566C80(s32);
s32 func_L00_00566D60(s32);

s32 func_L00_00567B10(s32 arg0, s32 arg1) {
    s32 v;
    Type2 *ctx;
    Type1 *so;
    Type1 *n;
    s32 nb;
    s32 r;
    s32 flags;
    s32 t;
    Type1 *p;
    Type1 *q;
    s32 u;

    ctx = func_L00_005669E0(0);
    if (ctx == NULL) {
        return -1;
    }
    so = func_L00_00566C80(arg0);
    if (so == NULL) {
        return func_L00_00566BA0(ctx, 9);
    }
    if (arg1 != 2 && arg1 != 0 && arg1 != 1) {
        return func_L00_00566BA0(ctx, 0x16);
    }
    flags = so->f10;
    nb = flags & 2;
    if (arg1 == 1) {
        so->f10 = flags | 8;
        if (so->fC != 0) {
            if (nb) {
                v = arg1;
                func_01E9BD30(ctx->f14, ctx->f54, so->fC, 0x13, &v, 4);
            }
            func_L00_005669C0();
            u = 0;
            if (!nb) {
                u = so->f6C;
            }
            v = u;
            func_01E9BD30(ctx->f14, ctx->f54, so->fC, 0x10, &v, 4);
            if (func_L00_00566950() < 0) {
                return func_L00_00566BA0(ctx, -1);
            }
        }
        if (!(so->f10 & 4)) {
            return func_L00_00566BA0(ctx, 0);
        }
    } else if (arg1 == 0) {
        so->f10 = flags | 4;
        if (so->fC != 0) {
            func_L00_005669C0();
            func_01E9BD30(ctx->f14, ctx->f54, so->fC, 0x15, NULL, 0);
            if (func_L00_00566950() < 0) {
                return func_L00_00566BA0(ctx, -1);
            }
        }
        if (!(so->f10 & 8)) {
            return func_L00_00566BA0(ctx, 0);
        }
    }
    r = 0;
    if (so->fC != 0) {
        if (nb) {
            v = 1;
            func_01E9BD30(ctx->f14, ctx->f54, so->fC, 0x13, &v, 4);
        }
        func_L00_005669C0();
        t = 0;
        if (!nb) {
            t = so->f6C;
        }
        r = func_01E9BB28(ctx->f14, ctx->f54, so->fC, t);
        if (func_L00_00566950() < 0) {
            return func_L00_00566BA0(ctx, -1);
        }
    }
    q = so->f0;
    p = so->f4;
    if (q != NULL) {
        q->f4 = p;
    } else {
        D_004A9BA4[0] = p;
    }
    if (so->f4 != NULL) {
        so->f4->f0 = so->f0;
    } else {
        D_004A9BA0[0] = so->f0;
    }
    while ((n = so->f54) != NULL) {
        so->f54 = n->f0;
        if (n->fC != 0) {
            func_L00_005669C0();
            func_01E9BB28(ctx->f14, ctx->f54, n->fC, 0);
            if (func_L00_00566950() < 0) {
                return func_L00_00566BA0(ctx, -1);
            }
        }
        func_L00_00566910(n);
    }
    func_L00_00566910(so);
    if (nb && r == -500) {
        return func_L00_00566BA0(ctx, 0);
    }
    if (r < 0) {
        return func_L00_00566BA0(ctx, func_L00_00566D60(r));
    }
    return func_L00_00566BA0(ctx, 0);
}
