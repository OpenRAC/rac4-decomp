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
    s32 f18;
    char f1C[0x10];
    s32 f2C;
    char _p30[0x38];
    s32 f68;
    s32 f6C;
} Type1;
typedef struct Type3 {
    u8 f0;
    u8 f1;
    u16 f2;
    char f4[1];
} Type3;

s32 func_01E9BAE0(void *, s32, s32, s32);
s32 func_01E9BB28(void *, s32, s32, s32);
s32 func_1E9BA68(void *, s32, void *);
extern s32 func_L00_00566950(void);
extern void func_L00_005669C0(void);
extern Type2 *func_L00_005669E0(s32 arg0);
s32 func_L00_00566BA0(void *, s32);
Type1 *func_L00_00566C80(s32);
void func_L00_00566CB8(void *, void *);
s32 func_L00_00566D30(u16);
s32 func_L00_00566D60(s32);
s32 func_L00_00567368(void *, void *);

/* Handles a multiplayer-menu reply packet for handle arg0. */
s32 func_L00_005673F8(s32 arg0, Type3 *arg1, s32 arg2) {
    Type2 *ctx;
    Type1 *req;
    s32 r;
    s32 flag;

    ctx = func_L00_005669E0(0);
    if (ctx == NULL) {
        return -1;
    }
    req = func_L00_00566C80(arg0);
    if (req == NULL) {
        return func_L00_00566BA0(ctx, 9);
    }
    if (arg2 != 0x10) {
        return func_L00_00566BA0(ctx, 0x16);
    }
    if (arg1->f1 != 2) {
        return func_L00_00566BA0(ctx, 0x6A);
    }
    func_L00_00566CB8(req->f1C, arg1->f4);
    req->f2C = func_L00_00566D30(arg1->f2);
    if (req->f18 == 0) {
        req->f18 = -1;
    }
    if (req->fC != 0) {
        if (req->f14 == 1) {
            return func_L00_00566BA0(ctx, 0x78);
        }
        if (req->f14 > 0) {
            if (req->f14 < 4) {
            func_L00_005669C0();
            func_01E9BB28(ctx->f14, ctx->f54, req->fC, req->f6C);
            req->fC = 0;
            if (func_L00_00566950() < 0) {
                return func_L00_00566BA0(ctx, -1);
            }
            }
        }
    }
    flag = req->f10 & 2;
    func_L00_005669C0();
    r = func_1E9BA68(ctx->f14, ctx->f54, &req->f14);
    if (func_L00_00566950() < 0) {
        return func_L00_00566BA0(ctx, -1);
    }
    if (r <= 0) {
        return func_L00_00566BA0(ctx, func_L00_00566D60(r));
    }
    if (req->f10 & 1) {
        return func_L00_00566BA0(ctx, 0x71);
    }
    req->fC = r;
    r = func_L00_00567368(ctx, req);
    if (r < 0) {
        return func_L00_00566BA0(ctx, func_L00_00566D60(r));
    }
    func_L00_005669C0();
    r = func_01E9BAE0(ctx->f14, ctx->f54, req->fC, flag ? 0 : req->f68);
    if (func_L00_00566950() < 0) {
        return func_L00_00566BA0(ctx, -1);
    }
    if (flag && r == -0x1F4) {
        return func_L00_00566BA0(ctx, 0x77);
    }
    if (r < 0) {
        return func_L00_00566BA0(ctx, func_L00_00566D60(r));
    }
    return func_L00_00566BA0(ctx, 0);
}
