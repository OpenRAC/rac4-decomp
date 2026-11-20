/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_L00_00514410(const u8 *arg0, const u8 *arg1, u32 count) {
    u32 i;
    for (i = 0; i < count; i++) {
        if (arg0[i] < arg1[i]) {
            return -1;
        }
        if (arg0[i] > arg1[i]) {
            return 1;
        }
    }
    return 0;
}
