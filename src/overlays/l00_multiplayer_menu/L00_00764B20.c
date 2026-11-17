#include "common.h"

extern s32 func_L00_005C9F50(s32);
extern s32 D_004EE640[];

// Resolve and store the five resource identifiers.
void func_L00_00764B20(void) {
    D_004EE640[0] = func_L00_005C9F50(0x2EA1);
    D_004EE640[1] = func_L00_005C9F50(0x2EC7);
    D_004EE640[2] = func_L00_005C9F50(0x2EC8);
    D_004EE640[3] = func_L00_005C9F50(0x23F3);
    D_004EE640[4] = func_L00_005C9F50(0x2EA2);
}
