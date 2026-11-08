#include "common.h"

extern s32 D_0021DAD8;
extern s32 D_00237074[];
extern s32 D_0021DEC4;
extern s32 D_00171D3E[];
extern s32 func_00453C68(s32, s32, f32);
extern void func_00454350(s32);
extern s32 func_0045E038(s32);
extern void func_00454A70(
    f32, f32, f32, unsigned long, s32, s32,
    f32, s32, s32, unsigned long, f32, f32
);
extern f32 func_00453928(f32);

/* from rac3-decomp's func_0038A3B8 */
void func_004496E0(void) {
    f32 f, y;
    s32 old, n;
    if (D_0021DAD8 == 1) {
        n = ((u8 *)D_00171D3E)[0xAD] ? 0x186 : 0x14f;
        f = (f32)(D_00237074[0] % 100) / 50.0f - 1.0f;
        if (f < -1.0f) f = -1.0f;
        if (1.0f < f) f = 1.0f;
        y = n;
        f = func_00453928(f * 3.1415927f);
        n = func_00453C68(0x7FE0E0E0, 0x5F66CCFF, (f + 1.0f) * 0.5f);
        old = D_0021DEC4;
        func_00454350(0);
        func_00454A70(
            256.0f, y, 1.0f, n, func_0045E038(0x244), -1,
            1.0f, 1, 1, 0x80000000, 1.0f, 1.0f
        );
        func_00454350(old);
    }
}
