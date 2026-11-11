#include "common.h"

extern void func_L00_006BB8E8(s32);
extern void func_L00_006EF5C0(void *, u32, s32, s32);
extern s32 func_L01_004F3128(void *, s32, s32);

typedef struct {
    u8 pad0[0x2B8];
    s32 f2B8;
    s32 f2BC;
    u8 pad2C0[0x2D8 - 0x2C0];
    s32 f2D8;
    u8 pad2DC[0x2E8 - 0x2DC];
    f32 f2E8;
} Target;

typedef struct {
    u8 pad0[0x8];
    Target *(*find)(s32);
} FinderVt;

typedef struct {
    u8 pad0[0x40];
    u8 f40;
    u8 pad41[0x4C - 0x41];
    FinderVt *vt;
} Ctx;

typedef struct {
    u8 pad0[0xB8];
    s32 fB8;
} Self;

void func_L01_004F2F20(Self *self, Ctx *ctx) {
    Target *t = ctx->vt->find(self->fB8);
    s32 n;
    s32 i;
    s32 flag;

    if (t == NULL || t->f2E8 <= 0.0f) {
        return;
    }
    n = 0;
    for (i = 0; i < 4; i++) {
        if (func_L01_004F3128(ctx, i, 0) != 0) {
            n++;
        }
    }
    if (n < 3) {
        return;
    }
    if (t->f2D8 & 4) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (t->f2B8 != 0) {
        func_L00_006BB8E8(t->f2B8);
    }
    if (t->f2BC != 0) {
        func_L00_006BB8E8(t->f2BC);
    }
    ctx->f40 = 1;
    if (flag) {
        func_L00_006EF5C0(t, 0xFFFFFFFF, 0xD, -1);
    }
}
