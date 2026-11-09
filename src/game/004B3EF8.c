#include "common.h"

typedef struct Type2 {
    s32 f0;
    s32 f4;
    char p8[0x14];
    void (*f1C)(struct Type2 *);
    s32 f20;
} Type2;

typedef struct {
    char p0[0x80];
    s32 f80;
    s32 f84;
    Type2 f88[6];
} Type1;

typedef struct {
    s32 f0;
    s32 f4;
} Type3;

extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004B3EA8(void);
extern void func_004B4A98(void);
extern s32 func_00504238(s32 handle, f32 a, f32 b);
extern void func_00505328(s32, s32);
extern Type3 D_003D1C48[];
extern s32 D_00221748;
extern Type1 D_003096A8[];

void func_004B3EF8(void) {
    Type1 *p;
    Type2 *e;
    s32 i;

    func_004B4A98();
    p = D_003096A8;
    p->f80 = 0;
    func_00504238(func_004A1A60(&D_00221748, 1), 0.5f, 0.5f);
    if (p->f84 != 0) {
        func_00504238(func_004A1A60(&D_00221748, 0xF), 0.5f, 0.5f);
        func_00504238(func_004A1A60(&D_00221748, 7), 0.5f, 0.5f);
        func_004B3EA8();
        for (i = 0; i < 6; i++) {
            e = &p->f88[i];
            e->f0 = e->f4;
            if (e->f1C != 0) {
                e->f1C(e);
            }
            func_00505328(func_004A1A60(&D_00221748, D_003D1C48[i].f4), 0x80D0D0D0);
        }
        return;
    }
    func_00504238(func_004A1A60(&D_00221748, 7), 0.5f, 0.15f);
}
