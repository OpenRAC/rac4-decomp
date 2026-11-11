/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 *D_00167F38;
/* Return the nested field or -1 if unavailable. */
s32 func_01EA55E8(void)
{
    u8 *p = D_00167F38;
    if (p) {
        p = *(u8 **)(p + 0x138);
        if (p) return *(s32 *)(p + 0x458);
    }
    return -1;
}
