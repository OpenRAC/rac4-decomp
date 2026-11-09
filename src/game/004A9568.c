/* cflags: -ffast-math */
#include "common.h"

typedef struct {
    char pad0[0x18];
    u8 f18;
    char pad19[3];
    f32 f1C;
    char pad20[0xC];
    u8 f2C;
    char pad2D[0xB];
    f32 f38[18];
    s32 f80;
    char pad84[8];
    s32 f8C;
    char pad90[8];
    s32 flags;
    char pad9C[4];
    s32 fA0;
    char padA4[0x14];
} Type1;

typedef struct {
    char pad[0x2F10];
    s32 f2F10;
} Type2;

extern Type1 D_00308108[];
extern s32 D_00221650;
extern s32 D_001711D0[];
extern s32 D_0021EDD4;
extern s32 D_003D1738[];
extern s32 D_003D17A0[][8];

extern s32 func_004534D0(s32 *arg0);
extern f32 func_00453928(f32);
extern f32 func_00453BA0(f32);
extern f32 func_004756D0(f32 a, f32 b, f32 t);
extern f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern void func_00497980(s32 arg0);
extern s32 func_00498158(s32, s32);
extern u32 func_004989C0(s32 a0, s32 a1);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004A8600(void);
extern s32 func_00505328(s32, s32);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);

void func_004A9568(void)
{
    s32 index = func_00505B20();
    Type1 *p = &D_00308108[index];
    s32 mode = func_004A8600();
    Type2 *obj = func_00510BE8(index);
    s32 i;

    if (D_001711D0[obj->f2F10] != 0) {
        p->f2C = 0x13;
    } else {
        p->f2C = 0x15;
    }
    if (p->f18 != 0) {
        f32 v = p->f1C + 0.02f;
        f32 r;
        v = v > 0.0f ? v : 0.0f;
        p->f1C = v;
        r = func_00453928(func_00453BA0(v * 6.282185f));
        r = func_004756D0(0.0f, 1.0f, (r + 1.0f) * 0.5f);
        func_00505410(func_004A1A60(&D_00221650, 0x23), r);
    }
    if (mode != 4) {
        p->fA0 = 100000000;
    } else if (func_004534D0(&p->fA0) == 0) {
        mode = p->f80;
    }
    if (mode != p->f80) {
        if (func_00498158(index, D_003D17A0[p->f8C][D_003D1738[mode]]) != 0) {
            p->f80 = mode;
            func_00497980(0x18);
            D_00308108[index].flags |= 9;
        }
    }
    p->f38[p->f80] = 1.0f;
    for (i = 0; i < 9; i++) {
        if ((D_0021EDD4 == 1 && p->f8C == D_0021EDD4 && i != p->f8C && i != 4) ||
            (i != 4 && D_003D17A0[p->f8C][D_003D1738[i]] == 0)) {
            func_00505328(func_004A1A60(&D_00221650, i + 6), 0x80404040);
            func_00505410(func_004A1A60(&D_00221650, i + 6), 1.0f);
        } else {
            s32 h;
            if (p->f80 != i) {
                func_004757E0(&p->f38[i], 0.0f, 0.1f, 0.05f);
            }
            h = func_004A1A60(&D_00221650, i + 6);
            func_00505328(h, func_004989C0(index, 0));
            func_00505410(func_004A1A60(&D_00221650, i + 6), p->f38[i]);
        }
    }
}
