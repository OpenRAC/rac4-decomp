#include "common.h"

extern u8 D_001CE3E8[];
extern s32 D_00221868;
extern s32 D_0022186C;
extern u8 D_00171E6B[];
extern void func_004B66B0(void);
extern s32 func_0049A9D8(const void *, s32);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_00506590(s32, s32);
extern s32 func_005071B8(s32, s32);
extern s32 func_005053D0(s32, f32);
extern s32 func_00505488(s32, f32);

void func_004B64A0(void)
{
    func_004B66B0();
    D_0022186C = func_0049A9D8(D_001CE3E8, -1);
    func_00506590(func_004A2798(&D_00221868, 0x15), 1);
    func_005071B8(func_004A2798(&D_00221868, 0x15), D_0022186C);
    func_005053D0(func_004A2798(&D_00221868, 1), -0.5f);
    func_005053D0(func_004A2798(&D_00221868, 0xB), 1.5f);
    if (D_00171E6B[0]) {
        func_00505488(func_004A2798(&D_00221868, 1), 0.405f);
        func_00505488(func_004A2798(&D_00221868, 0xB), 0.61f);
    }
}
