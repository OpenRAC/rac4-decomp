#include "common.h"

typedef struct {
    u8 prefix[0x14];
    s32 value;
} Config;
extern Config D_00171D38;
extern s32 D_002217E0;
extern void func_00497980(s32);
extern s32 func_004A1A60(s32 *, s32);
extern void func_00497AE0(s32, s32, s32, f32, f32);
void func_004BA508(s32 direction)
{
    s32 value;
    s32 first, second;
    if (direction) {
        D_00171D38.value += (s32)((f32)direction * 102.4f);
        if ((u32)D_00171D38.value >= 1025U)
            func_00497980(4);
        else
            func_00497980(17);
        value = D_00171D38.value;
        if (value >= 1025)
            value = 1024;
        if (value <= -1)
            value = 0;
        D_00171D38.value = value;
    }
    first = func_004A1A60(&D_002217E0, 25);
    second = func_004A1A60(&D_002217E0, 26);
    func_00497AE0(first, second, 0, (f32)D_00171D38.value * 0.0009765625f, 0.0f);
}
