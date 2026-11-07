/* Not matching yet on PAL: SIZE ours 100 / disc 104 (tools/check_func.py --version pal func_001469F8 --diff). Not part of the build. */
/* cflags: @ee29 */
/* Matched only with `*(volatile s32 *)0x10002010`: retail builds the hardware register's address
 * as a constant and rereads it in the loop, which only a volatile cast of the number gives, and
 * matched C may use neither volatile nor hardcoded addresses. */
#include "common.h"

extern s32 D_10002010[];

s32 func_001469F8(s32 mode, s32 reserved)
{
    u32 result = 0;
    switch (mode) {
    case 0: while (D_10002010[0] < 0) {} result = 0; break;
    case 1: result = (u32)D_10002010[0] >> 31; break;
    }
    return result;
}
