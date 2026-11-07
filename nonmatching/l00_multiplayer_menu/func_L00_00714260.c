/* Not matching yet: BYTES 12/36 (tools/try_func.py func_L00_00714260 --diff). Not part of the build. */
#include "common.h"

// Index the 0x45C table by the difference of the two 0x10A60 counters.
s32 func_L00_00714260(u8 *p) {
    s32 diff;

    diff = *(s32 *)(p + 0x10A60) - *(s32 *)(p + 0x10E74);
    return *(s32 *)(p + diff * 4 + 0x45C);
}
