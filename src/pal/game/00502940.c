#include "common.h"

/* Writes the two command values and restores the saved scalar state. */
extern s32 D_00222144;
extern s32 D_001DFD78[];
extern f32 D_00222140, D_002373F0[];
extern void func_00454B68(s32);
extern void func_004E88B8(s32, u64, s32);
extern void func_004481E8(void);
void func_00502940(void)
{
    func_00454B68(D_00222144);
    func_004E88B8(0x4E, 0x31000000 | (D_001DFD78[0] >> 13), 0);
    func_004E88B8(0x47, 0x3000D, 0);
    D_002373F0[0] = D_00222140;
    func_004481E8();
}
