/* Not matching yet: SIZE ours 100 / retail 104 (tools/try_func.py func_00406680 --diff). Not part of the build. */
#include "common.h"

// Rebuild a packed value: fold the top nibble to 0..7 (5 when zero) and keep
// the seven 3-bit fields below it.
u32 func_00406680(s32 value) {
    u32 out = 0;
    s32 top;
    s32 high;
    s32 i;

    top = value >> 28;
    if ((top & 7) != 0) {
        high = (top & 0xF) - ((top & 0xF) & 8);
    } else {
        high = 5;
    }
    for (i = 0; i < 7; i++) {
        out |= ((value >> (i * 4)) & 7) << (i * 4);
    }
    return (out & 0xFFFFFFF) | (high << 28);
}
