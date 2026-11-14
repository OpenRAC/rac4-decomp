/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EA9888(u8 *p, u32 v) {
    if (p == 0) {
        return 2;
    }
    *p++ = v;
    *p++ = v >> 8;
    *p++ = v >> 16;
    *p = v >> 24;
    return 0;
}
