/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9C7F0();
extern s32 D_001694FC[];
extern s32 D_1B26C0[];
extern s32 D_1B2700[];

/* Query a value into *out, mapping errors to status codes. */
s32 func_01EB5758(s32 a0, s32 a1, u32 a2, s32 *out)
{
    s32 flags;
    s32 r;
    s32 res;
    u32 n;

    flags = 0;
    if (!D_001694FC[0]) return 5;
    if (a0 < 0) return 2;
    n = 0x1000;
    if (a2 <= 0x1000) n = a2;
    r = func_01E9C7F0(D_1B26C0, D_1B2700, a0, a1, n, &flags, 2);
    if (r < 0) {
        res = 0xC350;
        if (flags & 4) res = 0xC356;
        return res;
    }
    if (flags & 4) {
        *out = r & 0xFFFF;
        return 0xC356;
    }
    *out = r;
    return 0;
}
