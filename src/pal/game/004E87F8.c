/* Reference: OpenRAC/rac2-decomp @ 99f35ac2c084fc59cdf3d631f8f960a825e7a49c; func_002FC468 (src/game/002FC468.c).
 * Independently reconstructed and checked against RAC4 PAL retail. */
#include "common.h"

extern u8 *D_00221F20;
extern void func_00453FE8(void *destination, const void *source, u32 bytes);

void func_004E87F8(u32 address, const void *source, u32 count)
{
    *(u32 *)(D_00221F20 + 0) = 0x10000000 | count;
    *(u32 *)(D_00221F20 + 4) = 0;
    *(u32 *)(D_00221F20 + 8) = 0x01000404;
    *(u32 *)(D_00221F20 + 12) = address | (count << 16) | 0x6C000000;
    D_00221F20 += 16;
    func_00453FE8(D_00221F20, source, count << 4);
    D_00221F20 += count << 4;
}
