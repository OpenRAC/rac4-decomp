#include "common.h"

typedef struct Type2 {
    s32 f0;
    s32 f4;
    char p8[0x14];
    void (*f1C)(struct Type2 *);
    s32 f20;
} Type2;

typedef struct {
    s32 f0;
    char p4[0x78];
    s32 f7C;
    s32 f80;
    s32 f84;
    Type2 f88[6];
    u8 f160;
} Type1;

typedef struct {
    s32 f0;
    s32 f4;
} Type3;

extern s32 func_00475858(f32, Type2 *, s32, s32);
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004B3EA8(void);
extern void func_004E19D8(s32 arg0, s32 arg1);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern void func_00505328(s32, s32);
extern Type3 D_003D1C48[];
extern s32 D_00221748;
extern Type1 D_003096A8[];

void func_004B2C80(void) {
    Type2 *e;

    D_003096A8->f7C = 1;
    e = &D_003096A8->f88[D_003096A8->f80];
    if (func_00475858(0.1f, e, e->f4, 1) != 0) {
        if (D_003096A8->f160 == 0) {
            D_003096A8->f160 = 1;
            func_004E21D8(e->f20, 4, 0);
        }
        func_00505328(func_004A1A60(&D_00221748, D_003D1C48[D_003096A8->f80].f4), 0x8020F0F0);
        if (e->f1C != 0) {
            e->f1C(e);
        }
        return;
    }
    if (D_003096A8->f160 != 0) {
        func_004E19D8(e->f20, 0);
    } else {
        func_00497980(0x2F);
    }
    func_00505328(func_004A1A60(&D_00221748, D_003D1C48[D_003096A8->f80].f4), 0x80D0D0D0);
    func_004B3EA8();
    D_003096A8->f7C = 10;
    D_003096A8->f160 = 0;
    if (D_003096A8->f80 < D_003096A8->f84) {
        D_003096A8->f80++;
    } else {
        D_003096A8->f80 = 0;
        D_003096A8->f0++;
    }
}
