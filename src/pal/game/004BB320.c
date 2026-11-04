#include "common.h"

typedef struct {
    u8 prefix[0x14];
    s32 value;
} Config;
extern Config D_00171DB8;
extern s32 D_002218E0;
extern void func_004985F0(s32);
extern s32 func_004A2798(s32 *, s32);
extern void func_00498818(s32, s32, s32, f32, f32);
void func_004BB320(s32 direction)
{
    s32 value;
    s32 first, second;
    if (direction) {
        D_00171DB8.value += (s32)((f32)direction * 102.4f);
        if ((u32)D_00171DB8.value >= 1025U)
            func_004985F0(4);
        else
            func_004985F0(17);
        value = D_00171DB8.value;
        if (value >= 1025)
            value = 1024;
        if (value <= -1)
            value = 0;
        D_00171DB8.value = value;
    }
    first = func_004A2798(&D_002218E0, 25);
    second = func_004A2798(&D_002218E0, 26);
    func_00498818(first, second, 0, (f32)D_00171DB8.value * 0.0009765625f, 0.0f);
}
