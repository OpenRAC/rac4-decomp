/* Not matching yet: BYTES 8/48 (tools/try_func.py func_01EB4E68 --diff). Not part of the build. */
#include "common.h"

extern s32 func_01EA9140();

// Store the value func_01EA9140 returns for arg1 in arg0 and report success.
s32 func_01EB4E68(s32 *arg0, s32 arg1) {
    s32 r = 0;

    *arg0 = func_01EA9140(arg1);
    return r;
}
