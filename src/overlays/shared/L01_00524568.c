#include "common.h"

extern u8 *D_222990;

// Mark the player's object as busy and clear the follow-up flag.
void func_L01_00524568(s32 arg0) {
    u8 *obj = *(u8 **)(D_222990 + arg0 * 0x20 + 0x1C);

    obj[0xB3] = 1;
    obj[0xB4] = 0;
}
