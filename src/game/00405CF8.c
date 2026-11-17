/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_00405CF8(s32 v, s32 n, s32 *arr) {
    s32 i;
    for (i = 0; i < n; i++) {
        if (v == *arr++) {
            return 0;
        }
    }
    return 1;
}
