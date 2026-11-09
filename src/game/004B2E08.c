#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x15C];
    u8 unk160;
} Type3096A8;

extern f32 func_004757E0(f32 *value, f32 target, f32 fraction, f32 minimum);
extern void func_00497980(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504238(s32, f32, f32);
extern void func_00504550(s32, void *, f32 *);
extern s32 D_00221748;
extern Type3096A8 D_003096A8;

void func_004B2E08(void) {
    f32 sp0;
    f32 sp4;

    if (D_003096A8.unk160 == 0) {
        D_003096A8.unk160 = 1;
        func_00497980(0x35);
    }
    func_00504550(func_004A1A60(&D_00221748, 1), &sp0, &sp4);
    if (func_004757E0(&sp4, 0.5f, 0.3f, 0.01f) != 0.0f) {
        func_00504238(func_004A1A60(&D_00221748, 1), sp0, sp4);
        return;
    }
    D_003096A8.unk160 = 0;
    D_003096A8.unk0++;
}
