/* Set the gp-relative byte flag to 1, then pass the helper result and 23 to another helper. */
#include "common.h"

void func_0049B1A0(s32, s32);
s32 func_00505B20();
extern s8 D_0021FC11;

void func_004D7810(void) {
    D_0021FC11 = 1;
    func_0049B1A0(func_00505B20(), 0x17);
}
