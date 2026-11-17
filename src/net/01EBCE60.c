/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EC2298(s32, s32);

s32 func_01EBCE60(u8 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 off;
    s32 t;
    u8 *p;

    i = arg1 & 0xFFFF;
    off = ((i << 2) + i) << 4;
    if (arg0 == 0) {
        return 2;
    }
    p = (u8 *)(off + *(s32 *)(arg0 + 0x184));
    if (*(s32 *)(p + 4) != 0) {
        t = func_01EC2298(*(s32 *)(p + 4), arg2);
        if (t != 0) {
            return t;
        }
    } else {
        if (*(s32 *)(p + 8) != 0) {
            t = func_01EC2298(*(s32 *)(p + 8), arg2);
            if (t != 0) {
                return t;
            }
        }
    }
    return 0;
}
