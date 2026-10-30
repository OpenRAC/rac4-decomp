#include "common.h"

/* Runs the pending callback once, arms the state flag if clear, then calls func_00464AF8(1). */
extern void func_00464AF8(int);
extern u8 D_00171948[];
void (*D_0021F164)(void) = 0;

void func_00464D50(void) {
    s32 *s;

    if (D_0021F164 != 0) {
        D_0021F164();
        D_0021F164 = 0;
    }
    s = (s32 *)D_00171948;
    if (s[0x1D4 / 4] == 0) {
        s[0x1E4 / 4] = 1;
    }
    func_00464AF8(1);
}
