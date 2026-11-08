/* Not matching yet: BYTES 3/64 (tools/try_func.py func_00547AC8 --diff). Not part of the build. */
#include "common.h"

extern s32 func_00548D28();

// True when the mode is not 1 and the object's byte at 0x2C is clear.
s32 func_00547AC8(s32 arg0) {
    s32 r = 1;
    s32 v;

    if (arg0 == 1) {
        return 0;
    }
    v = *(s8 *)(func_00548D28(arg0, 0) + 0x2C);
    r = v ? 0 : r;
    return r;
}
