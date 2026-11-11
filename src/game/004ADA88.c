/* cflags: -ffast-math */
#include "common.h"

typedef struct {
    char pad0[0x3D];
    u8 target;
    char pad3E[2];
    f32 value;
    f32 timer;
    char rest[0x8];
} State;

extern State D_003091A0[];
extern s32 D_00221690;
extern s32 func_00453C68(s32, s32, f32);
extern f32 func_004756D0(f32 a, f32 b, f32 t);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00505328(s32, s32);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_005058E0(u32 id, f32 a, f32 b);
extern s32 func_00505B20(void);

static inline f32 clamp01(f32 x)
{
    x = x < 1.0f ? x : 1.0f;
    return x > 0.0f ? x : 0.0f;
}

void func_004ADA88(void)
{
    State *p = &D_003091A0[func_00505B20()];
    u8 t = p->target;
    f32 v;

    if ((f32)t != p->value) {
        if (t != 0) {
            v = p->value + 0.2f;
        } else {
            v = p->value + -0.2f;
        }
        p->value = clamp01(v);
        func_00505410(func_004A1A60(&D_00221690, 5), p->value);
    }
    if (p->timer > 0.0f) {
        f32 s;
        s32 c;
        f32 tm = p->timer - 0.1f;
        p->value = clamp01(p->value);
        p->timer = tm;
        s = func_004756D0(0.9f, 2.0f, tm);
        c = func_00453C68(0x8020F0F0, 0x80FFFFFF, p->timer);
        func_005058E0(func_004A1A60(&D_00221690, 5), s, s * 1.33333f);
        func_00505328(func_004A1A60(&D_00221690, 5), c);
    }
}
