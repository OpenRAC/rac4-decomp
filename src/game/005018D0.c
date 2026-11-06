#include "common.h"

/* Writes the two command values and restores the saved scalar state. */
extern s32 D_00222044;
extern s32 D_001DFCF8[];
extern f32 D_00222040, D_002372F0[];
extern void func_00454350(s32);
extern void func_004E7990(s32, u64, s32);
extern void func_00447BA8(void);
void func_005018D0(void)
{
    func_00454350(D_00222044);
    func_004E7990(0x4E, 0x31000000 | (D_001DFCF8[0] >> 13), 0);
    func_004E7990(0x47, 0x3000D, 0);
    D_002372F0[0] = D_00222040;
    func_00447BA8();
}
