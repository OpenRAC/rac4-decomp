#include "common.h"
s32 func_L01_005723E8(u8 *p, u16 id)
{
    s32 i = 0;
    u16 *q;
    s32 n;
    if (p[0x91] != 0) {
        n = p[0x91];
        q = (u16 *)(p + 0x80);
        do {
            i++;
            if (*q == id) {
                return 1;
            }
            q++;
        } while (i < n);
    }
    return 0;
}
