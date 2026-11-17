/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9CC80();
extern s32 func_01EB4D80(u8 *p);
extern s32 D_001694FC[];
extern s32 D_1B26C0[];
extern s32 D_1B2700[];

/* Poll an entry; on data, report flag, length and checksum. */
s32 func_01EB58E8(s32 a0, s32 *flag, s32 *sum, s32 *len)
{
    u8 buf[16];
    u16 n;
    s32 r;

    *flag = 0;
    if (!D_001694FC[0]) return 5;
    if (a0 < 0) return 2;
    r = func_01E9CC80(D_1B26C0, D_1B2700, a0, &n, buf);
    if (r < 0) {
        if (r != -500) return 0xC350;
        r = 0;
    }
    if (r > 0) {
        *flag = 1;
        *len = n;
        *sum = func_01EB4D80(buf);
        return 0;
    }
    return 0;
}
