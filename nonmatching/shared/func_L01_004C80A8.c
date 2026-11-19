/* Not matching yet: SIZE ours 36 / retail 40 (tools/try_func.py func_L01_004C80A8 --diff). Not part of the build. */
#include "common.h"

s32 func_L01_004C80A8(u8 *arg0) {
    s32 r = 0;

    if (arg0[0x69] == 7) {
        if (arg0[0x20] == 0xF) {
            r = 1;
        }
    }
    return r;
}
