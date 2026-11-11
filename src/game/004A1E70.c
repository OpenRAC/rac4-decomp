#include "common.h"

extern s32 func_0045E038(s32);
extern void func_004661D8(void);
extern void func_0049F2F0(s32 arg0, void (*arg1)());
extern void func_0049F660(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void func_004A0040(s32 slot, s32 count, void *items);
extern void func_004A01D8(s32 arg0, s8 arg1);
extern void *func_004A1D88(void);
extern s32 func_004E21D8(u32 index, s32 param_a, s32 param_b);
extern void func_00501498(void *arg0);
extern s32 func_00505C90(void *arg0);

u8 D_0021F660 = 0;
s32 D_0021F664 = 1;
extern s32 D_003D90B8[];

void func_004A1E70(s32 arg0) {
    if (D_0021F660 != 0) {
        func_004661D8();
        D_0021F660 = 0;
    }
    if (D_0021F664 != 0) {
        func_004E21D8(5, 0, 0);
        D_0021F664 = 0;
    }
    D_003D90B8[1] = func_0045E038(0x23A2);
    D_003D90B8[4] = func_0045E038(0x23A3);
    D_003D90B8[7] = func_0045E038(0x23A4);
    D_003D90B8[10] = func_0045E038(0x2F25);
    D_003D90B8[13] = func_0045E038(0x14F);
    func_0049F660(arg0, 0.685f, 0.28f, 0.37109375f, 0.048076924f);
    func_004A01D8(arg0, 0);
    func_004A0040(arg0, 5, D_003D90B8);
    func_0049F2F0(arg0, 0);
    func_00501498(func_004A1D88());
    func_00505C90(func_004A1D88());
}
