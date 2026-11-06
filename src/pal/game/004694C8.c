/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/frontbin/39A6E0.c func_0039E788.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

extern u16 func_00469470(const void *, s32);
s32 func_004694C8(const s32 *packet)
{
    s32 result = 0;
    s32 checksum = packet[1];
    s32 size = packet[0];
    if (checksum != 0)
        result = func_00469470(packet + 2, size) == checksum;
    return result;
}
