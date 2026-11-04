/* C adapted from rac3-decomp func_003A9E88 (NTSC-U func_003A9D40, commit 403f30a9) */
#include "common.h"
extern s32 D_00221E48;
extern s32 D_00221E4C;
extern void func_001268D0(s32, s32);
extern void func_001276D0(s32);
void func_004E80F8(void) {
    if (*(volatile u32 *)0x1000E010 & 0x20000) {
        *(volatile u32 *)0x1000E010 = 0x20000;
    }
    func_001268D0(1, D_00221E48);
    func_001268D0(15, D_00221E4C);
    func_001276D0(1);
    D_00221E48 = 0;
    D_00221E4C = 0;
}

