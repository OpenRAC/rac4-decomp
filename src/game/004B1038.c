#include "common.h"

/* Clears bit arg0 in D_309650; if no bits remain, sets its third word to 2, otherwise calls func_0049A6B0(arg0, 0x200). */
extern void func_0049A6B0(s32 arg0, s32 arg1);
extern s32 D_309650[];

void func_004B1038(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_309650[0] & ~(1 << arg0);
    D_309650[0] = temp_v0;
    if (temp_v0 == 0) {
        D_309650[2] = 2;
        return;
    }
    func_0049A6B0(arg0, 0x200);
}
