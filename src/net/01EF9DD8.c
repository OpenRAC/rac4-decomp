/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

// Store arg1 into the word at +8 of each of the (count + 1) 0xC-byte records
// at *(arg0 + 0x118); the count is *(arg0 + 0xBC).
void func_01EF9DD8(void *arg0, s32 arg1) {
    u8 *base;
    s32 i;
    s32 off;

    i = 0;
    if ((*(s32 *)((u8 *)arg0 + 0xBC) + 1) > 0) {
        base = *(u8 **)((u8 *)arg0 + 0x118);
        off = 0;
        do {
            *(s32 *)(base + (off + 8)) = arg1;
            i += 1;
            off += 0xC;
        } while (i < (*(s32 *)((u8 *)arg0 + 0xBC) + 1));
    }
}
