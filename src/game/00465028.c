#include "common.h"

extern s32 D_00171948[];
void func_00464AF8(s32);

void func_00465028(void) {
    s32 *ptr = D_00171948;
    ptr[0x10 / 4] = 0;
    if (ptr[0x1CC / 4] < 0) {
        ptr[0x1D0 / 4] = 0;
        ptr[0x1CC / 4] = 3;
    }
    func_00464AF8(0xA);
}
