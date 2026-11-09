#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x7C];
    s32 unk80;
    u8 pad84[0xDC];
    u8 unk160;
} Type3096A8;

extern s32 func_0046A350(void);
extern s32 func_0046A358(void);
extern f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_004B3E20(void);
extern s32 func_00504238(s32, f32, f32);
extern void func_00504550(s32, void *, f32 *);
extern s32 D_00221748;
extern Type3096A8 D_003096A8;

void func_004B2F58(void) {
    f32 sp0;
    f32 sp4;
    s32 busy;

    if (func_0046A350() == 0 && func_0046A358() == 0) {
        D_003096A8.unk160 = 0;
        D_003096A8.unk0++;
        return;
    }
    busy = 0;
    if (D_003096A8.unk80 != 0) {
        func_00504550(func_004A1A60(&D_00221748, 7), &sp0, &sp4);
        if (func_004757E0(&sp4, 0.22999999f, 0.3f, 0.01f) != 0.0f) {
            busy = 1;
            func_00504238(func_004A1A60(&D_00221748, 7), sp0, sp4);
        }
        if (busy == 0) {
            func_004B3E20();
            D_003096A8.unk80 = 0;
            D_003096A8.unk160 = 0;
            D_003096A8.unk0++;
        }
    } else {
        if (D_003096A8.unk160 == 0) {
            D_003096A8.unk160 = 1;
            func_00497980(0x2D);
        }
        func_00504550(func_004A1A60(&D_00221748, 0xF), &sp0, &sp4);
        if (func_004757E0(&sp0, 1.35f, 0.3f, 0.01f) != 0.0f) {
            busy = 1;
            func_00504238(func_004A1A60(&D_00221748, 0xF), sp0, sp4);
        }
        func_00504550(func_004A1A60(&D_00221748, 1), &sp0, &sp4);
        if (func_004757E0(&sp4, 0.7f, 0.3f, 0.01f) != 0.0f) {
            busy = 1;
            func_00504238(func_004A1A60(&D_00221748, 1), sp0, sp4);
        }
        if (busy == 0) {
            D_003096A8.unk160 = 0;
            D_003096A8.unk80 = 1;
        }
    }
}
