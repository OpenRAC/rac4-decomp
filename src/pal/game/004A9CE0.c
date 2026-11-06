#include "common.h"

extern u8 D_00308208[];
extern s32 D_0021EE54;
extern s32 D_00221750;
extern s32 func_00506BB8(void);
extern void *func_00511CC0(s32);
extern s32 func_004A9450(void);
extern s32 func_005492C0(void *, s32);
extern s32 func_005495E0(void *, s32);
typedef struct Descriptor {
    u8 unknown0[8];
    s32 limit;
    u8 unknownC[0x14];
} Descriptor;
extern Descriptor *func_0054A2D0(s32, s32);
extern f32 func_005497E8(void *, s32);
extern s32 func_004A2798(s32 *, s32);
extern void func_00498818(s32, s32, s32, f32, f32);

void func_004A9CE0(void)
{
    s32 index = func_00506BB8();
    u8 *object = func_00511CC0(index);
    u8 *record = (u8 *)((u32)D_00308208 + (u32)index * 0xB8);
    s32 context = func_004A9450();
    f32 value;

    if (D_0021EE54 == 1) {
        s32 first = func_005492C0(*(void **)(object + 0x26E4), context);
        s32 second = func_005495E0(*(void **)(object + 0x26E4), context);
        Descriptor *table = func_0054A2D0(context, first);
        f32 numerator = (f32)second;
        f32 denominator = (f32)table->limit;
        value = numerator / denominator;
    } else {
        value = func_005497E8(*(void **)(object + 0x26E4), context);
    }
    if (context == 0) {
        value = 0.0f;
    }
    if (value == *(f32 *)(record + 0x7C)) {
        return;
    }
    *(f32 *)(record + 0x7C) = value;
    {
        s32 first = func_004A2798(&D_00221750, 0x2D);
        s32 second = func_004A2798(&D_00221750, 0x2E);
        func_00498818(first, second, 0, value, 0.0f);
    }
}
