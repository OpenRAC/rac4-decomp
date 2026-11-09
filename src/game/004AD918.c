#include "common.h"

extern s32 func_0049A6E0(f32 *value, f32 target);
extern void func_004ADA00(void);
extern void func_004ADA88(void);
extern void func_004ADC10(void);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);
extern s32 D_003091A0[];

void func_004AD918(s32 arg0)
{
    s32 *p;

    p = (s32 *)((u8 *)D_003091A0 + func_00505B20() * 0x50);
    switch (*p) {
    case 1:
        break;
    case 0:
        if (!(u8)func_0049A6E0((f32 *)(p + 1), 1.0f)) {
            *p = 1;
        }
        func_004ADA00();
        break;
    case 2:
        if (!(u8)func_0049A6E0((f32 *)(p + 1), 0.0f)) {
            func_005014B0(arg0);
        }
        func_004ADA00();
        break;
    }
    func_004ADA88();
    func_004ADC10();
}
