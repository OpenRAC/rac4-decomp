/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_1ACA00[];
extern void *D_1ACE00;

/* Point every 0x10-byte slot at the next one, then clear the last. */
void func_0012E8C8(void) {
    u8 *base = D_1ACA00;
    s32 i;
    s32 *entry;
    u8 *next;

    D_1ACE00 = base;
    next = base + 0x400;
    entry = (s32 *)(base + 0x3F0);
    for (i = 0x3F; i >= 0; i--) {
        *entry = (s32)next;
        entry = (s32 *)((u8 *)entry - 0x10);
        next -= 0x10;
    }
    (*(s32 *)(D_1ACA00 + 0x3F0)) = 0;
}
