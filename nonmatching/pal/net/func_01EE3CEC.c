/*
 * Not matching yet. PAL main:net.text 0x01EE3CEC, native 92 bytes.
 * Non-built WIP; default-PAL trial emitted 96 bytes. No matching credit.
 * Traversal-only loop and direct results recovered; max selection is hoisted,
 * and prologue/register/call-delay scheduling still differs from native.
 * Constructor is native-only / current NONMATCH void *(u32), not MATCH.
 * Existing caller Blk *(s32,u32) declaration is inherited local ABI debt;
 * no whole-program C-link or unique original-prototype claim.
 * Complete own B78 body retained unchanged below; see private review metadata.
 */
#include "common.h"

extern void *func_01EE3D48(u32);

u8 *func_01EE3CEC(u8 *first, u32 requested) {
    u32 initialCapacity = *(u32 *)first;
    u8 *current = first;
    u8 *next;
    u8 *created;

    for (;;) {
        u32 capacity = *(u32 *)current;
        u32 used = *(u32 *)(current + 4);
        if (capacity - used >= requested) {
            return current;
        }
        next = *(u8 **)(current + 0x10);
        if (next == NULL) {
            break;
        }
        current = next;
    }

    created = func_01EE3D48(requested >= initialCapacity ? requested : initialCapacity);
    *(u8 **)(current + 0x10) = created;
    return created;
}
