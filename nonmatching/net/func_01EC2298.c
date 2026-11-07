/* Not matching yet: BYTES 53/68 (tools/try_func.py func_01EC2298 --diff). Not part of the build. (tools/try_func.py func_01EC2298 --diff). Not part of the build. */
/* cflags: -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

// Copy the three words of a type 0xD record into `out`.
s32 func_01EC2298(u8 *p, s32 *out) {
    s32 r = 0xD2F3;

    if (p != 0 && *(s32 *)p == 0xD) {
        r = 2;
        if (out != 0) {
            r = 0;
            out[0] = *(s32 *)(p + 0x50);
            out[1] = *(s32 *)(p + 0x54);
            out[2] = *(s32 *)(p + 0x4C);
        }
    }
    return r;
}
