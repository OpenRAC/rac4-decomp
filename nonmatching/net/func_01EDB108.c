/* Not matching yet: BYTES 13/144 (tools/try_func.py func_01EDB108 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"
extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_1BC9D0[];
extern s32 D_1BCBC8[];
extern s32 D_21D994[];
extern s32 D_21D998[];
extern s32 func_01ED5DD0(s32, s32, s32, void *);
s32 func_01EDB108(u8 *obj, s32 arg1, s32 arg2)
{
    obj[0xC8] = 0;
    if (D_00169CD0 != 1) return -15;
    if (D_00169CD4 == 0) return -16;
    D_21D994[0] = *(s32 *)(obj + 0xAC);
    D_21D998[0] = *(s32 *)(obj + 0xB0);
    D_1BC9D0[0] = arg2;
    D_1BCBC8[0] = arg1;
    return func_01ED5DD0(1, 0xA7, 0xCC, obj) == 0 ? 0 : -5;
}
