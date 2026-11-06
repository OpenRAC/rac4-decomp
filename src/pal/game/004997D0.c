#include "common.h"

extern s32 D_0021EE54;
extern void *func_00511CC0(s32);
extern void *func_0054A290(s32, s32);
extern s32 func_005492C0(void *, s32);
extern s32 func_00499650(s32, s32);
extern f32 func_00475FF0(f32, f32, f32);
extern s32 func_00454480(s32, s32, f32);

s32 func_004997D0(s32 a0, s32 a1)
{
    void *object;
    s32 value;
    s32 color;

    if (D_0021EE54 != 1) {
        a0 = 0;
    }
    object = func_00511CC0(a0);
    if (*(u8 *)((u8 *)func_0054A290(a1, 0) + 0x28) != 0) {
        value = func_005492C0(*(void **)((u8 *)object + 0x26E4), a1);
        if (D_0021EE54 == 1 ? value > 0 : value >= 10) {
            s32 second;
            f32 blend;
            color = func_00499650(0, 0);
            if (D_0021EE54 != 1) {
                second = func_00499650(5, 0);
                blend = func_00475FF0((f32)value, 10.0f, 98.0f);
                color = func_00454480(color, second, blend);
            }
        } else
            color = 0x80D0D0D0;
    } else
        color = func_00499650(4, 3);
    return color;
}
