#include "common.h"

extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504238(s32, f32, f32);
extern void func_00504550(s32, void *, f32 *);
extern void func_00504648(s32, f32 *, f32 *);
extern s32 func_00504840(u32 a0, f32 a1, f32 a2, f32 a3, f32 a4);
extern s32 func_00505118(s32, f32 *, f32 *, f32 *, f32 *);
extern s32 D_00221728;
extern s32 D_00309654[];

void func_004B1758(void) {
    f32 sp0;
    f32 sp4;
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 offset;

    func_00504648(func_004A1A60(&D_00221728, 3), &sp0, &sp4);
    offset = sp4 * (f32)(D_00309654[0] - 1);
    func_00504550(func_004A1A60(&D_00221728, 0x1C), &sp8, &spC);
    func_00504238(func_004A1A60(&D_00221728, 0x1C), sp8, spC + offset);
    func_00505118(func_004A1A60(&D_00221728, 1), &sp10, &sp14, &sp18, &sp1C);
    func_00504840(func_004A1A60(&D_00221728, 1), sp10, sp14, sp18, sp1C + offset);
}
