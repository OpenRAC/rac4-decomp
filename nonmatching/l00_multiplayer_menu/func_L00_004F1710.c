/* Not matching yet: BYTES 13/40 (tools/try_func.py func_L00_004F1710 --diff). Not part of the build. */
#include "common.h"

// Swap the byte order of a 32-bit value.
u32 func_L00_004F1710(u32 value) {
    u32 r = value << 24;
    u32 t;

    t = (value & 0xFF00) << 8;
    r |= t;
    t = (value >> 8) & 0xFF00;
    r |= t;
    t = value >> 24;
    r |= t;
    return r;
}
