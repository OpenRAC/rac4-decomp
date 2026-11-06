/* C adapted from rac3-decomp func_003A9AF8 (NTSC-U func_003A99B0, commit 403f30a9) */
#include "common.h"
extern u32 *D_00221E20;
extern u8 D_001714F0[];
extern u8 D_00171580[];
extern void func_00453718();
void func_004E7CB0(void) {
    D_00221E20[0] = 0x30000009;
    D_00221E20[1] = (u32)D_001714F0;
    D_00221E20[2] = 0;
    D_00221E20[3] = 0x50000009;
    D_00221E20 += 4;
    D_00221E20[0] = 0x10000003;
    D_00221E20[1] = 0;
    D_00221E20[2] = 0;
    D_00221E20[3] = 0x50000003;
    D_00221E20 += 4;
    func_00453718(D_00221E20, D_00171580, 0x30);
    D_00221E20 = (u32 *)((u8 *)D_00221E20 + 0x30);
}

