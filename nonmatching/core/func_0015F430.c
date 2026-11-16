/* Not matching yet: BYTES 77/108 (tools/try_func.py func_0015F430 --diff) (tools/try_func.py func_0015F430 --diff). Not part of the build. */
#include "common.h"

s32 D_00172160[1403];

s32 func_0015F430(s32 arg0) {
    s32 found = 0;
    s32 i = 0;

    if (D_00172160[1387] == arg0) {
        found = 1;
        D_00172160[1387] = -1;
    } else {
        do {
            i++;
            if (D_00172160[1387 + i] == arg0) {
                found = 1;
                D_00172160[1387 + i] = -1;
                break;
            }
        } while (i < 16);
    }
    return found;
}
