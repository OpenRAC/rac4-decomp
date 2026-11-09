/* cflags: -G0 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

// Swap the byte order of a 32-bit value.
u32 func_L00_005669A8(u32 value) {
    u32 r = value << 24;
    u32 t;

    t = (value & 0xFF00) << 8;
    r = r | t;
    t = (value >> 8) & 0xFF00;
    r = r | t;
    t = value >> 24;
    r = r | t;
    return r;
}