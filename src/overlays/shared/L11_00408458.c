#include "common.h"

extern u8 *func_00532080(s32, s32);

// Calls func_00532080(0x275E, 0x10); if it returns an object, sets its byte at +0x30 to 0xFF
// and fills the four words at its +0xAC pointer with 180 and the three arguments.
void func_L11_00408458(s32 arg0, s32 arg1, s32 arg2) {
    u8 *moby = func_00532080(0x275E, 0x10);
    if (moby != NULL) {
        s32 *vars = *(s32 **)(moby + 0xAC);
        moby[0x30] = 0xFF;
        vars[0] = 0xB4;
        vars[2] = arg1;
        vars[3] = arg2;
        vars[1] = arg0;
    }
}
