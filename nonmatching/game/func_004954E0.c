/* Not matching yet: BYTES 8/48 (tools/try_func.py func_004954E0 --diff). Not part of the build. */
#include "common.h"

/* Clamp current + step into the range the first word allows. */
s64 func_004954E0(s32 *count, s32 current, s32 step) {
    s32 last;

    current += step;
    if (step < 0) {
        if (current < 0) {
            current = 0;
        }
    } else {
        last = *count - 1;
        if (last < current) {
            current = last;
        }
    }
    return current;
}
