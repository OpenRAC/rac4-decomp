#include "common.h"

extern u8 *func_L00_005F1AE8(const u8 *owner);

s32 func_L01_005A4648(const u8 *owner)
{
    u8 *state = func_L00_005F1AE8(owner);
    if (state != NULL) {
        s32 old = state[0xA];
        state[0xA] = 0;
        return old != 0;
    }
    return 0;
}
