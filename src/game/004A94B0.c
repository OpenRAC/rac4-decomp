#include "common.h"

typedef struct {
    char pad[0x88];
    f32 f88;
    char pad8C[0x10];
    f32 f9C;
    char tail[0x18];
} Type1;
extern Type1 D_00308108[];
extern s32 D_00221650;
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504238(s32, f32, f32);
extern s32 func_00505410(u32 id, f32 amount);
extern s32 func_00505B20(void);
// Combines two fractions of the current entry of D_00308108 and feeds them to two calls on handle 0x24.
void func_004A94B0(void)
{
    s32 index = func_00505B20();
    Type1 *p = (Type1 *)((u32)index * 0xB8 + (u32)D_00308108);
    f32 v = 1.0f - (1.0f - p->f9C) * (1.0f - p->f88);
    func_00504238(func_004A1A60(&D_00221650, 0x24), v * 0.0f + 0.5f, v * -0.1f + 0.5f);
    func_00505410(func_004A1A60(&D_00221650, 0x24), 1.0f - v);
}
