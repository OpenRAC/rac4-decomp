/* cflags: @ee296 -O2 -G0 */
#include "common.h"
/* Not matching yet: BYTES 2/52 (tools/try_func.py func_01EEA974 --diff). Not part of the build. */
/* Returns 1 unless func_01EEC260 gives 0 or 2, in which case it returns 0. */
s32 func_01EEC260();

s32 func_01EEA974(void) {
    s32 temp = func_01EEC260();

    if (temp == 0 || temp == 2) {
        return 0;
    }
    return 1;
}
