#include "common.h"

/* Clears bit arg0 in D_3095B0; if no bits remain, sets its second word to 2, otherwise calls func_0049A6B0(arg0, 0x40). */
extern void func_0049A6B0(s32 arg0, s32 arg1);
extern s32 D_3095B0[];

void func_004AFFC8(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_3095B0[0] & ~(1 << arg0);
    D_3095B0[0] = temp_v0;
    if (temp_v0 == 0) {
        D_3095B0[1] = 2;
        return;
    }
    func_0049A6B0(arg0, 0x40);
}
