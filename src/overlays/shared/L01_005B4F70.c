#include "common.h"

extern void *func_00595D00(void);
/* Stores arg1 at +0x31 of the record func_00595D00 returns and sets +0xC to 1 when it changes; returns the old byte, or 0 without a record. */
u8 func_L01_005B4F70(s32 unused, s32 arg1) {
    u8 old;
    u8 *p;

    p = (u8 *)func_00595D00();
    if (p == 0) {
        return 0;
    }
    old = p[0x31];
    if (old != arg1) {
        p[0x31] = arg1;
        *(s32 *)(p + 0xC) = 1;
    }
    return old;
}
