#include "common.h"
typedef struct {
    char pad[0x88];
    f32 value;
    char pad8C[0xC];
    u32 flags;
    char tail[0x1C];
} State;
extern State D_00308208[];
extern s32 D_00221750;
extern s32 func_00506BB8(void), func_004A2798(s32 *, s32);
extern s32 func_005052D0(s32, f32, f32), func_005064A8(s32, f32);
void func_004AA638(void)
{
    s32 index = func_00506BB8();
    f32 value = ((State *)((u32)index * 0xB8 + (u32)D_00308208))->value;
    f32 inv = 1.0f - value;
    func_005052D0(func_004A2798(&D_00221750, 1), inv * -0.1f + 0.5f, inv * 0.0f + 0.5f);
    func_005064A8(func_004A2798(&D_00221750, 1), value);
    D_00308208[index].flags |= 0x100;
}
