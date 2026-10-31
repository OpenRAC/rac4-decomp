#include "common.h"

extern void func_00464AF8(int);
extern u8 D_00171948[];

// Calls func_00464AF8 with 0x13 or 0xB when the state at 0x1C4 is 2 and the field at 0x1CC is negative.
void func_00465068(void) {
    s32 *ptr = (s32 *)D_00171948;

    if (ptr[0x1C4 / 4] == 2 && ptr[0x1CC / 4] < 0) {
        if (ptr[0x1D4 / 4] != 0) {
            func_00464AF8(0x13);
        } else {
            func_00464AF8(0xB);
        }
    }
}
