/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001694FC[];
extern s32 D_1B26C0[];
extern s32 D_1B2700[];
extern s32 func_01E9CA90();
extern s32 func_01EB4D80(u8 *p);

/* Read an entry into buffers, report its length and checksum. */
s32 func_01EB5810(s32 a0, s32 *a1, s32 *a2, s32 a3, u32 len, s32 *res)
{
    u8 buf[16];
    s32 flags;
    s32 n;
    s32 out;
    s32 r;

    flags = 0;
    if (!D_001694FC[0]) return 5;
    if (a0 < 0) return 2;
    *res = 0;
    n = 0x1000;
    if (len <= 0x1000) n = len;
    r = func_01E9CA90(D_1B26C0, D_1B2700, a0, a3, n, &flags, buf, &out, 2);
    if (r < 0) {
        if (r != -500) return 0xC350;
        r = 0;
    }
    if (r > 0) {
        *a2 = out;
        *a1 = func_01EB4D80(buf);
    }
    *res = r;
    return 0;
}
