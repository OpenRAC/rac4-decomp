/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    struct Type1 *next;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

typedef struct Type2 {
    u8 pad0[0x14];
    u8 f14[0x40];
    s32 f54;
} Type2;

typedef struct Type3 {
    u8 pad0[0xC];
    s32 fC;
    s32 f10;
    u8 pad14[0x40];
    Type1 *f54;
    s32 f58;
    Type1 *f5C;
} Type3;

s32 func_1E9BCE8(void *, s32, s32, s32);
s32 func_L00_00566950(void);
void func_L00_005669C0(void);
Type2 *func_L00_005669E0(s32);
s32 func_L00_00566BA0(Type2 *, s32);
Type3 *func_L00_00566C80(s32);
s32 func_L00_00566D60(s32);

s32 func_L00_00566EF8(s32 arg0, s32 arg1) {
    Type2 *ctx;
    Type3 *ent;
    Type1 *node;
    s32 ret;

    ctx = func_L00_005669E0(0);
    if (ctx == NULL) {
        return -1;
    }
    ent = func_L00_00566C80(arg0);
    if (ent == NULL) {
        return func_L00_00566BA0(ctx, 9);
    }
    if (ent->fC != 0) {
        func_L00_005669C0();
        ret = func_1E9BCE8(ctx->f14, ctx->f54, ent->fC, arg1);
        if (func_L00_00566950() < 0) {
            return func_L00_00566BA0(ctx, -1);
        }
        if (ret < 0) {
            return func_L00_00566BA0(ctx, func_L00_00566D60(ret));
        }
    } else {
        ent->f10 |= 1;
    }
    for (node = ent->f54; node != NULL; node = node->next) {
        if (node->fC != 0) {
            func_L00_005669C0();
            func_1E9BCE8(ctx->f14, ctx->f54, node->fC, arg1);
            if (func_L00_00566950() < 0) {
                return func_L00_00566BA0(ctx, -1);
            }
        }
    }
    for (node = ent->f5C; node != NULL; node = node->next) {
        if (node->fC != 0) {
            func_L00_005669C0();
            func_1E9BCE8(ctx->f14, ctx->f54, node->fC, arg1);
            if (func_L00_00566950() < 0) {
                return func_L00_00566BA0(ctx, -1);
            }
        }
    }
    func_L00_00566BA0(ctx, 0);
    return 0;
}
