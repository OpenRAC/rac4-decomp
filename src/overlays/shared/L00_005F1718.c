#include "common.h"

extern s32 D_00244CD8[];
s32 D_0021E744 = 0;

// Clear five entries and a global flag.
void func_L00_005F1718(void) {
    s32 i = 4;
    s32 *ptr = D_00244CD8;
    ptr += i;
    do {
        *ptr = 0;
        i--;
        ptr--;
    } while (i >= 0);
    D_0021E744 = 0;
}
