/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    char _p0[0x14];
    char f14[0x40];
    s32 f54;
} Type2;
typedef struct Type1 {
    char _p0[0xC];
    s32 fC;
    s32 f10;
    s32 f14;
    char _p18[0x64 - 0x18];
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} Type1;

typedef struct Type3 {
    s64 f0;
    s64 f8;
} Type3;

s64 func_0012EF00(s64, s64);
s32 func_01E9BD30(void *, s32, s32, s32, void *, s32);
s32 func_L00_00566950(void);
void func_L00_005669C0(void);
Type2 *func_L00_005669E0(s32 arg0);
s32 func_L00_00566BA0(void *, s32);
Type1 *func_L00_00566C80(s32);
void func_L00_00566CB8(void *, void *);
s32 func_L00_00566D60(s32);
s32 func_L00_00567650(Type2 *arg0, Type1 *arg1);

s32 func_L00_00567E30(s32 arg0, s32 arg1, s32 arg2, s32 *arg3, s32 arg4) {
    char b0[0x10];
    char b10[0x10];
    char b20[0x10];
    char b30[0x10];
    char b40[0x10];
    s32 v50;
    Type1 *so;
    Type2 *ctx;
    s32 minlen;
    s32 r;
    s64 t;

    r = -1;
    ctx = func_L00_005669E0(0);
    if (ctx == NULL) {
        return -1;
    }
    so = func_L00_00566C80(arg0);
    if (so == NULL) {
        return func_L00_00566BA0(ctx, 9);
    }
    if (arg1 == 0xFFFF) {
        if ((u32)(arg2 - 0x1001) < 2 || arg2 == 0x1009) {
            minlen = 4;
        } else if ((u32)(arg2 - 0x1005) < 2) {
            minlen = 0x10;
        } else {
            return func_L00_00566BA0(ctx, 0x6D);
        }
    } else if (arg1 == 6) {
        if (so->fC == 0) {
            return func_L00_00566BA0(ctx, 0x6D);
        }
        if ((u32)(so->f14 - 1) >= 2 || arg2 != 1) {
            return func_L00_00566BA0(ctx, 0x6D);
        }
        minlen = 4;
    } else if (arg1 == 0) {
        if (so->f14 != 0) {
            return func_L00_00566BA0(ctx, 0x6D);
        }
        if (arg2 == 9) {
            minlen = 4;
        } else if (arg2 == 10) {
            minlen = 4;
        } else if (arg2 == 11) {
            minlen = 4;
        } else if (arg2 == 12) {
            minlen = 8;
        } else if (arg2 == 13) {
            minlen = 8;
        } else {
            return func_L00_00566BA0(ctx, 0x6D);
        }
        r = func_L00_00567650(ctx, so);
        if (r != 0) {
            return func_L00_00566BA0(ctx, r);
        }
    } else {
        return func_L00_00566BA0(ctx, 0x6D);
    }

    if (arg3 == NULL || arg4 < minlen) {
        return func_L00_00566BA0(ctx, 0x16);
    }

    if (arg1 == 0xFFFF) {
        if (arg2 == 0x1001) {
            so->f70 = *arg3;
            if (so->fC != 0) {
                func_01E9BD30(ctx->f14, ctx->f54, so->fC, 0xD, &so->f70, 4);
            }
        } else if (arg2 == 0x1002) {
            so->f74 = *arg3;
            if (so->fC != 0) {
                func_01E9BD30(ctx->f14, ctx->f54, so->fC, 0xF, &so->f74, 4);
            }
        } else if (arg2 == 0x1009) {
            if (*arg3 != 0) {
                so->f10 |= 2;
            } else {
                so->f10 &= ~2;
            }
        } else if ((u32)(arg2 - 0x1005) < 2) {
            t = ((Type3 *)arg3)->f0 * 1000;
            t += func_0012EF00(((Type3 *)arg3)->f8 + 500, 1000);
            minlen = t;
            if (minlen <= 0) {
                minlen = -1;
            }
            if (arg2 == 0x1005) {
                so->f6C = minlen;
                so->f68 = minlen;
            } else if (arg2 == 0x1006) {
                so->f64 = minlen;
            }
        }
    } else {
        func_L00_005669C0();
        if (arg1 == 6 && arg2 == 1) {
            v50 = *arg3 != 0;
            r = func_01E9BD30(ctx->f14, ctx->f54, so->fC, 3, &v50, 4);
        } else if (arg1 == 0) {
            if (arg2 == 9) {
                func_L00_00566CB8(b0, arg3);
                r = func_01E9BD30(ctx->f14, ctx->f54, so->fC, 4, b0, 0x10);
            } else if (arg2 == 10) {
                r = func_01E9BD30(ctx->f14, ctx->f54, so->fC, 6, arg3, minlen);
            } else if (arg2 == 11) {
                r = func_01E9BD30(ctx->f14, ctx->f54, so->fC, 8, arg3, minlen);
            } else if (arg2 == 12) {
                func_L00_00566CB8(b10, arg3);
                func_L00_00566CB8(b20, arg3 + 1);
                r = func_01E9BD30(ctx->f14, ctx->f54, so->fC, 0xA, b10, 0x20);
            } else if (arg2 == 13) {
                func_L00_00566CB8(b30, arg3);
                func_L00_00566CB8(b40, arg3 + 1);
                r = func_01E9BD30(ctx->f14, ctx->f54, so->fC, 0xB, b30, 0x20);
            }
        }
        if (func_L00_00566950() < 0) {
            return func_L00_00566BA0(ctx, -1);
        }
        if (r < 0) {
            return func_L00_00566BA0(ctx, func_L00_00566D60(r));
        }
    }
    return func_L00_00566BA0(ctx, 0);
}
