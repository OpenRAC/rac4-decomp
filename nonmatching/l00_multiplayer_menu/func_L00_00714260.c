/* Not matching yet: BYTES 9/36 (tools/try_func.py func_L00_00714260 --diff). Not part of the build. (tools/try_func.py func_L00_00714260 --diff). Not part of the build. */
/* cflags: -fno-schedule-insns2 */
#include "common.h"

// Index the 0x45C table by the difference of the two 0x10A60 counters.
s32 func_L00_00714260(s32 *p) {
    return p[(p[0x4298] - p[0x439D]) + 0x117];
}
