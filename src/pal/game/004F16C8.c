#include "common.h"

/* Reference: OpenRAC/OpenRAC@73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde
 * OpenRAC/games/rac3/ntsc/src/frontbin/3ABA48.c func_003ABA48.
 * Independently reconstructed from RAC4 PAL retail. */
typedef struct Stream Stream;
typedef struct {
    u8 prefix[8];
    u8 *source;
    s32 size;
    u64 first, second;
} Block;
extern Stream *D_00221FD4;
extern char D_003D3210[];
extern void func_004F2C78(Stream *, u8 **, s32 *, u8 **, s32 *);
extern s32 func_004F18B0(u8 *, s32, u8 *, s32, const u8 *, s32, const u8 *, s32);
extern s32 func_004F2D20(Stream *, u64, u64, const u8 *, s32);
extern void func_004F0708(const char *);
extern void func_004F2C98(Stream *, s32);
s32 func_004F16C8(s32 unused, Block *block, const u8 *buffer)
{
    u8 *first, *second;
    s32 firstSize, secondSize;
    s32 offset = *(const s32 *)(buffer + 0x50008);
    const u8 *source = block->source;
    s32 size = block->size;
    s32 count = (s32)((u32)buffer + offset - (u32)source);
    s32 remaining;
    s32 copied;
    if (size < count)
        count = size;
    remaining = size - count;
    func_004F2C78(D_00221FD4, &first, &firstSize, &second, &secondSize);
    copied = func_004F18B0((u8 *)(((u32)first & 0x0FFFFFFF) | 0x20000000), firstSize,
                           (u8 *)(((u32)second & 0x0FFFFFFF) | 0x20000000), secondSize, source, count, buffer, remaining);
    if (copied > 0) {
        if (!func_004F2D20(D_00221FD4, block->first, block->second, first, copied))
            func_004F0708(D_003D3210);
    }
    func_004F2C98(D_00221FD4, copied);
    return copied > 0;
}
