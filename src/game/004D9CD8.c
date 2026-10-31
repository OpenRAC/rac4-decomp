#include "common.h"

extern void func_00499CE0(s32 arg0);
extern s32 func_00505B20(void);
extern void func_00505D30(s32 arg0);
extern u8 D_321650[];

/* Clear the pending value in the slot selected by the current index and release it. */
void func_004D9CD8(void) {
    s32 temp_a0;
    u8 *temp_s0;

    temp_s0 = D_321650 + func_00505B20() * 0x124;
    func_00505D30(0xF);
    temp_a0 = *(s32 *)(temp_s0 + 0x120);
    if (temp_a0 != 0) {
        func_00499CE0(temp_a0);
        *(s32 *)(temp_s0 + 0x120) = 0;
    }
}
