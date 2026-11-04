/* cflags: -O2 -G8 -fopt-stack -Wuninitialized */
#include "common.h"

extern s32 D_001721E0[];
extern s32 D_00220B54;
extern s32 D_00220B58;

/* Publish the selected pair, preserving -1 as the absent selection. */
void func_L00_0070F328(void)
{
    D_00220B58 = D_001721E0[0x124 / sizeof(s32)];
    if (D_001721E0[0x124 / sizeof(s32)] != -1) {
        D_00220B54 = D_001721E0[0x128 / sizeof(s32)];
        return;
    }
    D_00220B54 = D_001721E0[0x124 / sizeof(s32)];
}
