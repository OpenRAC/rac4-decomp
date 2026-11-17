/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EA9850(u8 *arg0, u16 *arg1) {
    if (arg0 == NULL) {
        return 2;
    }
    if (arg1 == NULL) {
        return 2;
    }
    *arg1 = arg0[0];
    *arg1 |= arg0[1] << 8;
    return 0;
}
