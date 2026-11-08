#include "common.h"

extern u8 D_375B50[];

// True when the entry's first byte is 1.
s32 func_L41_0040E518(s32 arg0, s32 arg1) {
    return *(u8 *)(D_375B50 + arg1 * 0x18 + arg0 * 0x60) == 1;
}
