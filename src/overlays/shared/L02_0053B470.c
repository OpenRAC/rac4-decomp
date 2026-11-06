#include "common.h"

extern void func_005D7008(void *, s32);

// Update the state flags and notify the linked object when needed (state is cleared when active is 0).
void func_L02_0053B470(u8 *state, s32 active) {
    u8 *source;

    if (active != 0) {
        source = *(u8 **)(state + 0x24);
        *(u16 *)(state + 0x34) &= 0xFFBE;
        *(u16 *)(state + 0x34) |= *(u16 *)(source + 0x44) & 0x1000;
        *(s32 *)(state + 0x98) = *(s32 *)(source + 0x10);
        return;
    }
    *(s32 *)(state + 0x98) = 0;
    *(u16 *)(state + 0x34) = (*(u16 *)(state + 0x34) | 0x41) & 0xEFFF;
    func_005D7008(state, 1);
}
