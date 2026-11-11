#include "common.h"

extern s32 D_0021EDD4;
extern void *func_00510BE8(s32);
extern void *func_00548D28(s32, s32);
extern s32 func_00547D58(void *, s32);
extern s32 func_00498918(s32, s32);
extern f32 func_00475710(f32, f32, f32);
extern s32 func_00453C68(s32, s32, f32);

s32 func_00498A98(s32 a0, s32 a1)
{
    void *object;
    s32 value;
    s32 color;

    if (D_0021EDD4 != 1) {
        a0 = 0;
    }
    object = func_00510BE8(a0);
    if (*(u8 *)((u8 *)func_00548D28(a1, 0) + 0x28) != 0) {
        value = func_00547D58(*(void **)((u8 *)object + 0x26E4), a1);
        if (D_0021EDD4 == 1 ? value > 0 : value >= 10) {
            s32 second;
            f32 blend;
            color = func_00498918(0, 0);
            if (D_0021EDD4 != 1) {
                second = func_00498918(5, 0);
                blend = func_00475710((f32)value, 10.0f, 98.0f);
                color = func_00453C68(color, second, blend);
            }
        } else
            color = 0x80D0D0D0;
    } else
        color = func_00498918(4, 3);
    return color;
}
