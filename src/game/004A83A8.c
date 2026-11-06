#include "common.h"

extern int func_00505B20(void);
extern char D_00308108[];
extern int D_00221650;
extern s32 func_00505410(s32, f32);
extern s32 func_00504238(s32, f32, f32);
/* Scale the selected channel and adjust its output values. */
void func_004A83A8(void)
{
    char *p = D_00308108 + func_00505B20() * 0xB8;
    float a = *(float *)(p + 0x30) * *(float *)(p + 0x34);
    func_00505410(D_00221650, a);
    func_00504238(D_00221650, (1.0f - a) * -0.3f + 0.5f, 0.5f);
}
