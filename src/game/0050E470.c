#include "common.h"

extern u8 func_00454A60(void);
extern void func_00454A68(s32 arg0);
extern void func_00454A70(f32, f32, f32, f32, u64, const void *, s32, s32, s32, u64, f32, f32);
extern void func_004571E0(void);
extern void func_00457200(void);
extern void func_0050C368(void *, void *);
extern s32 func_0050E420(u8 *arg0, u8 arg1);
extern f32 D_00220AC4;
extern f32 D_00220AC8;
extern f32 D_00220AE4;
extern f32 D_00220AE8;
extern f32 D_00220B00;

typedef struct {
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    s32 f10;
    s32 f14;
} Type2;

typedef struct Type1 Type1;
typedef struct {
    char _p0[0x28];
    void (*f28)(Type1 *, s32, Type2 *, s32);
} Type3;

struct Type1 {
    char _p0[0x8];
    Type3 *f8;
    u32 fC;
    char _p10[0xC];
    f32 f1C;
    char _p20[0x4];
    f32 f24;
    f32 f28;
    char _p2C[0x4];
    u32 f30;
    u32 f34;
    char _p38[0x14];
    void *f4C;
};

static inline u64 func_0050E470_bit(u64 x, s32 n) {
    return (x >> n) & 1;
}

/* Draws the object's text at the centre of its rect, with an optional offset shadow pass, alpha scaled by arg2. */
void func_0050E470(Type1 *arg0, s32 arg1, f32 arg2) {
    Type2 r;
    f32 cx;
    f32 cy;
    f32 ox;
    f32 oy;
    u32 color;
    u8 old;

    if (arg0->f4C != 0) {
        r.x0 = 0.0f;
        r.y0 = 0.0f;
        r.x1 = 1.0f;
        r.y1 = 1.0f;
        r.f10 = 0;
        r.f14 = 0;
        arg0->f8->f28(arg0, arg1, &r, 1);
        func_0050C368(arg0, &r);
        cx = r.x0 + (r.x1 - r.x0) * 0.5f;
        cy = r.y0 + (r.y1 - r.y0) * 0.5f;
        if (func_0050E470_bit(arg0->fC, 6)) {
            ox = arg0->f24;
            oy = arg0->f28;
            func_00457200();
            color = arg0->f34;
            if (arg2 < 0.999f) {
                color = (color & 0xFFFFFF) | ((s32)((f32)(color >> 24) * arg2) << 24);
            }
            old = func_00454A60();
            func_00454A68(func_0050E420((u8 *)arg0, 2));
            func_00454A70((s32)((cx + ox) * D_00220AE4),
                          (s32)((cy + oy - D_00220B00 * arg0->f1C) * D_00220AE8),
                          arg0->f1C * D_00220AC4, arg0->f1C * D_00220AC8, color, arg0->f4C, -1, 1, 0, 0, 0.0f, 0.0f);
            func_00454A68(old);
            func_004571E0();
        }
        color = arg0->f30;
        if (arg2 < 0.999f) {
            color = (color & 0xFFFFFF) | ((s32)((f32)(color >> 24) * arg2) << 24);
        }
        old = func_00454A60();
        func_00454A68(func_0050E420((u8 *)arg0, 2));
        func_00454A70((s32)(cx * D_00220AE4),
                      (s32)((cy - D_00220B00 * arg0->f1C) * D_00220AE8),
                      arg0->f1C * D_00220AC4, arg0->f1C * D_00220AC8, color, arg0->f4C, -1, 1, 0, 0, 0.0f, 0.0f);
        func_00454A68(old);
        func_004571E0();
    }
}
