#include "common.h"

extern u8 *func_L00_005F44F8(const u8 *owner);

s32 func_L01_005A89C0(const u8 *owner)
{
    u8 *state = func_L00_005F44F8(owner);
    if (state != NULL) {
        s32 old = state[0xA];
        state[0xA] = 0;
        return old != 0;
    }
    return 0;
}
