/* Not matching yet: BYTES 37/72 (tools/try_func.py func_01EC2298 --diff). Not part of the build. */
/* cflags: -G0 */
#include "common.h"

// Copy the three words of a type 0xD record into `out`.
s32 func_01EC2298(u8 *p, s32 *out) {
    s32 r = 0xD2F3;
    s32 magic;
    s32 type;

    magic = 0xD;
    if (p != 0) {
        type = *(s32 *)p;
        if (type == magic) {
            if (out == 0) {
                return 2;
            }
            r = 0;
            out[0] = *(s32 *)(p + 0x50);
            out[1] = *(s32 *)(p + 0x54);
            out[2] = *(s32 *)(p + 0x4C);
        }
    }
    return r;
}
