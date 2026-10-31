#include "common.h"

extern void *func_004765F0(void);
/* Stores arg1 at +0x30 of the record func_004765F0 returns and sets +0xC to 1 when it changes; returns the old byte, or 0 without a record. */
u8 func_004887D8(s32 unused, s32 arg1) {
    u8 old;
    u8 *p;

    p = (u8 *)func_004765F0();
    if (p == 0) {
        return 0;
    }
    old = p[0x30];
    if (old != arg1) {
        p[0x30] = arg1;
        *(s32 *)(p + 0xC) = 1;
    }
    return old;
}
