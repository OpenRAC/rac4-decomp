/* cflags: -mno-split-addresses */
#include "common.h"

extern void *func_L00_005F2FB8(void);

/* Returns the word at 0x1C0 of the table entry indexed by arg0, or 0 when arg0 is 4 or more. */
s32 func_L01_005A54F0(u32 arg0) {
    u8 *base;
    u32 off;

    if (arg0 < 4) {
        base = func_L00_005F2FB8();
        off = arg0 * 4;
        return *(s32 *)(base + off + 0x1C0);
    }
    return 0;
}
