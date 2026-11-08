/* cflags: -mno-split-addresses */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u128 D_00222C50;
extern void func_00473078(u128 *, f32, f32);
extern s32 func_00472E70(s32, s32);
extern void func_L01_005D6B28(u128 *, u128 *, f32, f32, f32, f32, s32, s32, s32, s32, s32);
extern void func_00493E80(u128 *, s32, s32, s32, s32, u128, s32, f32, f32, f32);
extern void func_00494D98(u128 *, f32, f32, s32, s32, s32, s32, u128 *, s32, s32, s32, s32);

// Ten calls of func_L01_005D6B28 from the given position with a random direction, then four
// func_00493E80 and three func_00494D98 calls with fixed parameters around it.
void func_L01_00413548(u128 pos) {
    u128 dir;
    u128 *ref = &D_00222C50;
    s32 i;

    for (i = 9; i >= 0; i--) {
        func_00473078(&dir, 0.10000001f, 0.20000002f);
        func_L01_005D6B28(&pos, &dir, 0.075f, 0.25f, 0.5f, 0.5f, (func_00472E70(10, 25) * 5 + 2) / 6, 0x80004EFF,
                          0xFF, 0, 0);
    }
    func_00493E80(&pos, 0xE, 0x80004EFF, 2, 1, *ref, 1, 3.5f, 0.1f, 0.0f);
    func_00493E80(&pos, 0xE, 0x80004EFF, 2, -1, *ref, 1, 2.5f, 0.1f, 0.0f);
    func_00493E80(&pos, 0xE, 0xC0FFFFFF, 2, 1, *ref, 1, 1.75f, 0.1f, 0.0f);
    func_00493E80(&pos, 0xE, 0xB0FFFFFF, 2, -1, *ref, 1, 1.25f, 0.1f, 0.0f);
    func_00494D98(&pos, 0.71999997f, 0.56f, 0x11, 0x46787878, 2, 2, ref, 0, 2, 6, 1);
    func_00494D98(&pos, 1.36f, 0.56f, 0x11, 0x46787878, 2, -1, ref, 1, 2, 6, 1);
    func_00494D98(&pos, 1.6f, 1.2f, 0x11, 0x2D787878, 2, 1, ref, 1, 2, 6, 1);
}
