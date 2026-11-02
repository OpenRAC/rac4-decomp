#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 func_L01_004289F0(u128 *, u128 *, void *, s32, s32 *, s32, u32, f32, f32);
extern void func_L01_00428BB0(s32, s32);
extern void func_L01_00428BF0(s32, s32);
extern void func_L01_00441588(s32, u128, s32, s32, u32, u32, f32, f32, f32);

// Calls func_L01_004289F0 with copies of arg1 and arg2, a word set to 0x80000000, 10.0 and the
// linked byte at +0x28B as a float; when it returns non-zero, calls func_L01_00428BB0(r, 4),
// func_L01_00428BF0(r, 30) and func_L01_00441588 on the linked word at +0x5F0 with arg1.
void func_L01_0045AC80(u8 *arg0, u128 arg1, u128 arg2) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    u128 pos = arg1;
    u128 dir = arg2;
    s32 mask = 0x80000000;
    s32 shot;

    shot = func_L01_004289F0(&pos, &dir, arg0, 1, &mask, -1, 0xFFFFFFFF, 10.0f, (f32)vars[0x28B]);
    if (shot != 0) {
        func_L01_00428BB0(shot, 4);
        func_L01_00428BF0(shot, 0x1E);
        func_L01_00441588(*(s32 *)(vars + 0x5F0), pos, 0, -1, 0x84204080, 0x84204080, 0.5f, 1.0f, 1.25f);
    }
}
