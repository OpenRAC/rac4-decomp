#include "common.h"

typedef struct {
    char pad0[0x8];
    char name1[0x10];
    char name2[0x10];
    s32 v28;
    s32 v2C;
    s32 v30;
    s32 v34;
    s32 v38;
    u8 v3C;
    char pad3D[0x13];
} State;

extern State D_003091A0[];
extern s32 D_00221690;
extern s32 D_00171B40[];
extern s32 func_00475858(f32, s32 *, s32, s32);
extern void func_004979A8(void *, s32, s32);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00505328(s32, s32);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_00505B20(void);

void func_004ADC10(void)
{
    State *p = &D_003091A0[func_00505B20()];
    s32 now = D_00171B40[0];
    s32 diff = now - p->v2C;
    s32 n;

    p->v28 = now;
    if (diff != 0) {
        n = p->v34 + 1;
        p->v34 = n < 6 ? n : 5;
        func_00505410(func_004A1A60(&D_00221690, 4), (f32)p->v34 / 5.0f);
        if (diff != p->v30 && p->v3C == 0) {
            p->v38 = 60;
            p->v30 = diff;
            func_004979A8(p->name2, diff, 1);
            func_00505328(func_004A1A60(&D_00221690, 4), p->v30 > 0 ? 0x8020F0F0 : 0x803050FF);
            return;
        }
        if (p->v38 != 0) {
            p->v38--;
            return;
        }
        p->v30 = diff;
        p->v3C = 1;
        diff = func_00475858(0.1f, &p->v30, 0, 1);
        if (diff != 0) {
            p->v2C -= diff;
            func_004979A8(p->name2, p->v30, 1);
            func_004979A8(p->name1, p->v2C, 0);
        }
    } else if (p->v34 > 0) {
        p->v34--;
        func_00505410(func_004A1A60(&D_00221690, 4), (f32)p->v34 / 5.0f);
        p->v3C = p->v34 > 0;
    }
}
