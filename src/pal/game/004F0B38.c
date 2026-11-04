/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/frontbin/3B0048.c func_003B0470.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

typedef struct {
    u8 prefix[0x48];
    s32 base;
    s32 size;
    u8 gap[8];
    s32 cursor;
} Ring;
void func_004F0B38(s32 *first, s32 *first_size, s32 *second, s32 *second_size, const Ring *ring, s32 position)
{
    s32 size = ring->size;
    s32 cursor = ring->cursor;
    s32 remainder = (((position + size) - cursor) - 0x400) % size;
    if ((u32)(position - cursor) < 0x400U) {
        *first = ring->base;
        *first_size = 0;
        *second = ring->base;
        *second_size = 0;
        return;
    }
    remainder = (remainder / 1024) * 1024;
    if (size - cursor >= remainder) {
        *first = ring->base + cursor;
        *first_size = remainder;
        *second = 0;
        *second_size = 0;
        return;
    }
    *first = ring->base + cursor;
    *first_size = ring->size - ring->cursor;
    *second = ring->base;
    *second_size = remainder - (ring->size - ring->cursor);
}
