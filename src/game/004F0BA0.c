/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/frontbin/3B0FF0.c func_003B1530.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

typedef struct {
    u32 base;
    u32 descriptor;
    s32 entries;
} Transfer;
s32 func_004F0BA0(const Transfer *transfer, u32 address)
{
    s32 bytes = transfer->entries * 16 + 16;
    u32 end = (transfer->descriptor + bytes) & 0x0FFFFFFF;
    if (address == end)
        return 0;
    return (address - transfer->base) >> 11;
}
