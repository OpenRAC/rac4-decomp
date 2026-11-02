#include "common.h"

extern f32 func_00454328(f32, f32);
extern s32 func_00453D20(void *);
extern void func_0046C6B0(u8 *);

// Scales +0x70 by the remaining part of the timer at +0x1C, spins the three angles at +0xF0,
// deletes the object when the timer runs out, else fades +0x23 in over the first half.
void func_L01_003DCB10(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    s32 half;

    *(f32 *)(arg0 + 0x70) = (f32)(*(s32 *)(vars + 0x14) - *(s16 *)(vars + 0x1C)) * *(f32 *)(vars + 0x18) /
                            (f32)*(s32 *)(vars + 0x14);
    *(f32 *)(arg0 + 0xF0) = func_00454328(*(f32 *)(arg0 + 0xF0), 0.06283186f);
    *(f32 *)(arg0 + 0xF4) = func_00454328(*(f32 *)(arg0 + 0xF4), 0.06283186f);
    *(f32 *)(arg0 + 0xF8) = func_00454328(*(f32 *)(arg0 + 0xF8), 0.06283186f);
    if (func_00453D20(vars + 0x1C) != 0) {
        func_0046C6B0(arg0);
        return;
    }
    half = *(s32 *)(vars + 0x14) / 2;
    if (*(s16 *)(vars + 0x1C) < half) {
        arg0[0x23] = *(s16 *)(vars + 0x1C) * *(s16 *)(vars + 0x1E) / half;
    }
}
