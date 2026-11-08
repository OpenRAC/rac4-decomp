/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EACEF0(s32 *arg0) {
    s32 i;

    for (i = 0; i < 0x80; i++) {
        if (arg0[i] != 0) {
            return 0;
        }
    }
    return 1;
}
