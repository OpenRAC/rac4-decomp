/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 *D_003C5A00[];
extern u32 D_003C5A04[];
extern u32 D_003C5A08[];

/* Copy up to LEN bytes from the read cursor of the buffer into DST, advance the
   cursor by what was copied and return that count. */
s32 func_003F38F8(u8 *dst, s32 len)
{
    u32 idx = D_003C5A04[0];
    u32 size = D_003C5A08[0];
    u32 end = idx + len;
    s32 n = len;
    s32 i = 0;
    u8 *src;

    if (size < end) {
        n = size - idx;
    }
    src = D_003C5A00[0] + idx;
    for (; i < n; i++) {
        dst[i] = src[i];
    }
    D_003C5A04[0] += n;
    return n;
}
