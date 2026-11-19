/* cflags: @ee296 -O2 -G8 */
#include "common.h"

s32 func_L00_00513F10(u8 *a, u8 *b, u32 n) {
    u32 i;

    for (i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            return -1;
        }
        if (a[i] > b[i]) {
            return 1;
        }
    }
    return 0;
}
