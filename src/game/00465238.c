#include "common.h"

extern u8 D_00171948[];
extern s32 D_21DAE4;
extern void func_00464AF8(s32);

// Calls func_00464AF8 with 4, 5 or 0xF depending on the state at 0x1C4 and the fields at 0x8, 0x10 and 0x1CC.
void func_00465238(void) {
    s32 *p = (s32 *)D_00171948;
    s32 st = p[0x1C4 / 4];

    if (st == 2 && p[0x1CC / 4] < 0) {
        if (p[0x8 / 4] != st) {
            func_00464AF8(4);
        } else if (p[0x10 / 4] != 0) {
            func_00464AF8(5);
        } else if (D_21DAE4 & 0x12) {
            func_00464AF8(0xF);
        }
    }
}
