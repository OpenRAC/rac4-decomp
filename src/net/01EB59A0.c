/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001694FC;
extern s32 func_01E9D348(s32, u32 *);
s32 func_01EB59A0(s32 fd, s32 *out) {
    u32 flags = 0;
    s32 r;
    if (D_001694FC == 0) {
        return 5;
    }
    if (fd < 0) {
        return 2;
    }
    *out = 0;
    r = func_01E9D348(fd, &flags);
    if (r < 0) {
        if (r >= -510 && r <= -508) {
            return 0xC356;
        }
        return 0xC350;
    }
    if (flags & 4) {
        return 0xC356;
    }
    *out = r;
    return 0;
}
