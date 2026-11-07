/* Not matching yet: BYTES 9/40 (tools/try_func.py func_01EAECF0 --diff). Not part of the build. */
#include "common.h"

extern u16 D_00196760;

void func_01EAECF0(s32 *arg0) {
    if ((D_00196760 >> 8) == 0x23) {
        *arg0 = 1;
    } else {
        *arg0 = 0;
    }
}
