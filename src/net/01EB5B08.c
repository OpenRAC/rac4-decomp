/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001694FC[];
extern u8 D_1B26C0[];
extern u8 D_1B2700[];
extern s32 func_01E9D2A0(void *, void *, s32, s32, void *, s32);
extern s32 func_01EB4D80(void *);

s32 func_01EB5B08(s32 arg0, s32 *arg1)
{
    u8 buf[0x4C];

    if (!D_001694FC[0]) return 5;
    if (arg0 < 0) return 2;
    if (func_01E9D2A0(D_1B26C0, D_1B2700, arg0, 1, buf, 0x4C) != 1)
        return 0xC350;
    *arg1 = func_01EB4D80(buf + 0x24);
    return 0;
}
