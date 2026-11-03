#include "common.h"

/* Control-flow reference: OpenRAC/OpenRAC 73f725bf54bb1bf6d8b9bb5b1511ed00d551fbde,
 * games/rac3/ntsc/src/frontbin/3896E8.c:func_0038C840.
 * Reconstructed against RAC4 PAL retail. */
extern void func_00455288(f32, f32, f32, f32, u64, const char *, s32, s32, s32, u64, f32, f32);
void func_00457E60(u64 color, const char *first, s32 second, f32 x, f32 y, f32 depth)
{
    func_00455288(x, y, depth, depth, color, first, second, 0, 0, 0x80000000ULL, 0.0f, 0.0f);
}
