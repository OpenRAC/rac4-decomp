#include "common.h"

extern int func_00506BB8(void);
extern char D_00308208[];
extern int D_00221750;
extern s32 func_005064A8(s32, f32);
extern s32 func_005052D0(s32, f32, f32);
/* Scale the selected channel and adjust its output values. */
void func_004A9118(void)
{
    char *p = D_00308208 + func_00506BB8() * 0xB8;
    float a = *(float *)(p + 0x30) * *(float *)(p + 0x34);
    func_005064A8(D_00221750, a);
    func_005052D0(D_00221750, (1.0f - a) * -0.3f + 0.5f, 0.5f);
}
