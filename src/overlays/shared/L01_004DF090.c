#include "common.h"

extern s32 func_00472590(s32, s32);
extern f32 func_00472690(void);
extern void func_L01_004DF2A0(u8 *, s32, f32, s32, s32, f32, f32, s32, u8 *);

s32 D_00222310 = 0;
s32 D_00222314 = 0;
s32 D_00222348 = 0;
s32 D_0022234C = 0;
f32 D_00222350 = 0.0f;
f32 D_00222354 = 0.0f;

/* from rac2-decomp's func_L12_004081F8 */
void func_L01_004DF090(u8 *a0) {
    func_L01_004DF2A0(a0 + 0x10, D_00222310, D_00222350 * *(f32 *)(a0 + 0x70),
                      func_00472590(0x5F, 0x6F), D_00222348, func_00472690(),
                      1.0f, 2, a0);
    {
        f32 size = D_00222350 * *(f32 *)(a0 + 0x70) * D_00222354;
        func_L01_004DF2A0(a0 + 0x10, D_00222314, size,
                          func_00472590(0x6F, 0x7F), D_0022234C,
                          func_00472690(), 1.0f, 2, a0);
    }
}
