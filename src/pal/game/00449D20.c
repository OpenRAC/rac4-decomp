#include "common.h"

extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
void func_00389D60(void (*callback)(s32), s32 argument);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
void func_00389F18(void (*callback)(s32), s32 argument);
extern void (*D_00226A00[])(s32);
extern void (*D_001D9C18[])(int);
extern void (*D_001D9C18_00389FE0)(s32);
extern void func_00455288(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern s32 D_0021DB58;
extern s32 D_00237174[];
extern s32 D_0021DF4C;
extern s32 D_00171DBE[];
extern void func_00454480(s32, s32, f32);
extern void func_00454B68(s32);
extern s32 func_0045E850(s32);
extern void func_00455288(
    f32, f32, f32, unsigned long, s32, s32,
    f32, s32, s32, unsigned long, f32, f32
);
extern f32 func_00454140(f32);

/* PAL: from rac3-decomp's func_0038A3B8 */
void func_00449D20(void) {
    f32 f, y;
    s32 old, n;
    if (D_0021DB58 == 1) {
        n = ((u8 *)D_00171DBE)[0xAD] ? 0x186 : 0x14f;
        f = (f32)(D_00237174[0] % 100) / 50.0f - 1.0f;
        if (f < -1.0f) f = -1.0f;
        if (1.0f < f) f = 1.0f;
        y = n;
        f = func_00454140(f * 3.1415927f);
        n = ((s32 (*)(s32, s32, f32))func_00454480)(
            0x7FE0E0E0, 0x5F66CCFF, (f + 1.0f) * 0.5f
        );
        old = D_0021DF4C;
        func_00454B68(0);
        func_00455288(
            256.0f, y, 1.0f, n, func_0045E850(0x244), -1,
            1.0f, 1, 1, 0x80000000, 1.0f, 1.0f
        );
        func_00454B68(old);
    }
}
