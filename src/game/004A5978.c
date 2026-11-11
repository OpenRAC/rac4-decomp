#include "common.h"

typedef struct Type1 {
    f32 f0;
    f32 f4;
    char _p8[0x4];
    f32 fC;
    f32 f10;
    char _p14[0xC];
    f32 f20;
    f32 f24;
    u8 u28;
    char _p29[0x3];
    f32 f2C;
    char _p30[0x8];
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    f32 f4C;
} Type1;

extern void func_004534D0(s32 *timer);
extern f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern void func_004A5B18(void);
extern s32 func_00505B20(void);
extern s32 D_0021EDD4;
extern Type1 D_00307F68[];

void func_004A5978(void)
{
    s32 changed = 0;
    Type1 *s = &D_00307F68[func_00505B20()];

    if (func_004757E0(&s->f2C, s->u28, 0.0f, 0.05f) != 0.0f) {
        changed = 1;
    }
    if (s->f10 != s->fC) {
        if (s->u28 != 0) {
            s->f10 = s->fC;
        } else if (s->f38 != 0) {
            func_004534D0(&s->f38);
        } else {
            func_004757E0(&s->f10, s->fC, 0.1f, 0.3f);
        }
        changed = 1;
    } else {
        s->f38 = 30;
    }
    if (s->f4 != s->f0) {
        if (s->u28 == 0) {
            s->f4 = s->f0;
        } else if (s->f3C != 0) {
            func_004534D0(&s->f3C);
        } else {
            func_004757E0(&s->f4, s->f0, 0.1f, 0.3f);
        }
        changed = 1;
    } else {
        s->f3C = 30;
    }
    if (D_0021EDD4 != 1 && s->f24 != s->f20) {
        s->f24 = s->f20;
    }
    func_004A5B18();
    s->f44 = changed;
}
