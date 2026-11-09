#include "common.h"

extern s32 func_0045E038(s32);
extern void func_00497980(s32 arg0);
extern void func_0049F2F0(s32 arg0, void (*arg1)());
extern void func_0049F660(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void func_004A0040(s32 arg0, s32 arg1, void *arg2);
extern void func_004A01D8(s32 arg0, s8 arg1);
extern void func_004A01F0(s32 arg0, s32 arg1);
extern void func_004A28D0();

extern u8 D_00171DF5[];
extern s32 D_003D9110[];

void func_004A2700(s32 arg0) {
    D_003D9110[1] = func_0045E038(0x150);
    D_003D9110[4] = func_0045E038(0x151);
    D_003D9110[7] = func_0045E038(0x152);
    switch (D_00171DF5[0]) {
    case 4:
        func_004A01F0(arg0, 2);
        break;
    case 2:
        func_004A01F0(arg0, 1);
        break;
    default:
        func_004A01F0(arg0, 0);
        break;
    }
    func_0049F660(arg0, 0.685f, 0.28f, 0.37109375f, 0.048076924f);
    func_004A01D8(arg0, 0);
    func_004A0040(arg0, 3, D_003D9110);
    func_0049F2F0(arg0, func_004A28D0);
    func_00497980(0xB);
}
