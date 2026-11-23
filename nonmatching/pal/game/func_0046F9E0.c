/* Not matching yet: PAL WIP; main .text 0x0046F9E0, 284B. Not part of the build. */
/*
 *  0x0070 addu $v0, $v0, $s3 | addu $v0, $s3, $v0
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 3b71fefe5e5aaa15006983568c90b48d08c473092a3c69403905ba10525f9c09
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0046F9E0 nonmatching/pal/game/func_0046F9E0.c --diff
 */
#include "common.h"

extern void *func_0046F8C0(void *object);

void *func_0046F9E0(void *object, s32 sourceAddress, s32 tag, s32 duration,
                   f32 sample, s32 byte1, s32 byte2)
{
    u8 **slot;
    u8 *node;
    u8 *current;
    u16 halfword;

    node = func_0046F8C0(object);
    if (node != NULL) {
        *(u8 *)(node + 0x16) = byte1;
        *(u8 *)(node + 0x17) = byte2;
        *(u8 *)(node + 0x14) = tag;
        *(s32 *)(node + 0) = sourceAddress;
        *(f32 *)(node + 4) = sample;
        *(u8 *)(node + 0x15) = 0;
        halfword = *(u16 *)((u8 *)sourceAddress + (s32)sample * 4 + 0x20);
        *(f32 *)(node + 8) = 1.0f;
        *(u16 *)(node + 0xC) = halfword;
        *(f32 *)(node + 0x1C) = 0.0f;
        if (duration > 0) {
            *(f32 *)(node + 0x1C) = -1.0f / (f32)duration;
        }
        *(f32 *)(node + 0x18) = -*(f32 *)(node + 0x1C);
        slot = (u8 **)((u8 *)object + 0x50);
        if (*(u8 **)((u8 *)object + 0x50) != NULL) {
            do {
                current = *slot;
                slot = (u8 **)(current + 0x10);
            } while (*(u8 **)(current + 0x10) != NULL);
        }
        *slot = node;
        *(u8 **)(node + 0x10) = NULL;
    }
    return node;
}
