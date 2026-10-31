#include "common.h"

extern void func_00464AF8(s32);
extern u8 D_00171948[];
extern u8 D_0021EE19;
extern s32 D_21DAE4;

/* Calls func_00464AF8 with a code picked from the state at D_00171948 and two flags. */
void func_00464F28(void) {
    s32 *p = (s32 *)D_00171948;
    if (p[2] != 2) {
        func_00464AF8(4);
    } else if (p[4] != 0) {
        func_00464AF8(5);
    } else if (D_0021EE19 != 0 || (D_21DAE4 & 0x1A)) {
        func_00464AF8(8);
    }
}
