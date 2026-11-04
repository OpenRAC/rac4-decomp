#include "common.h"

/* Reference: OpenRAC/OpenRAC@73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde
 * OpenRAC/games/rac3/ntsc/src/frontbin/3ABA48.c func_003AD108.
 * Independently reconstructed from RAC4 PAL retail. */
typedef struct Stream {
    u8 prefix[0x48];
    u8 ring[0x60];
    s32 state;
} Stream;
typedef struct {
    u8 bytes[4];
} Command;
extern Command D_002209B8[];
extern Stream *D_00221FD4;
extern void func_004F2C78(Stream *, u8 **, s32 *, u8 **, s32 *);
extern s32 func_004F31A0(u8 *, s32, u8 *, s32, const void *, s32, const void *, s32);
extern void func_004F2C98(Stream *, s32);
extern void func_004F2728(void *);
s32 func_004F2D88(Stream *stream)
{
    Command command = D_002209B8[0];
    u8 *first;
    s32 firstSize;
    u8 *second;
    s32 secondSize;
    s32 copied;
    func_004F2C78(stream, &first, &firstSize, &second, &secondSize);
    if (firstSize + secondSize < 4)
        return 0;
    copied = func_004F31A0((u8 *)(((u32)first & 0x0FFFFFFF) | 0x20000000), firstSize,
                           (u8 *)(((u32)second & 0x0FFFFFFF) | 0x20000000), secondSize, &command, 4, 0, 0);
    func_004F2C98(D_00221FD4, copied);
    func_004F2728(stream->ring);
    if (stream->state == 0)
        stream->state = 2;
    return 1;
}
