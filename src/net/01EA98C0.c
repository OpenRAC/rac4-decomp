/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EA98C0(u8 *arg0, u32 *arg1) {
    if (arg0 == NULL) {
        return 2;
    }
    if (arg1 == NULL) {
        return 2;
    }
    *arg1 = *arg0++;
    *arg1 |= *arg0++ << 8;
    *arg1 |= *arg0++ << 16;
    *arg1 |= *arg0++ << 24;
    return 0;
}
