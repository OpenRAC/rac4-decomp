#include "common.h"
typedef struct {
    char pad[0x88];
    f32 value;
    char pad8C[0xC];
    u32 flags;
    char tail[0x1C];
} State;
extern State D_00308108[];
extern s32 D_00221650;
extern s32 func_00505B20(void), func_004A1A60(s32 *, s32);
extern s32 func_00504238(s32, f32, f32), func_00505410(s32, f32);
void func_004A98C0(void)
{
    s32 index = func_00505B20();
    f32 value = ((State *)((u32)index * 0xB8 + (u32)D_00308108))->value;
    f32 inv = 1.0f - value;
    func_00504238(func_004A1A60(&D_00221650, 1), inv * -0.1f + 0.5f, inv * 0.0f + 0.5f);
    func_00505410(func_004A1A60(&D_00221650, 1), value);
    D_00308108[index].flags |= 0x100;
}
