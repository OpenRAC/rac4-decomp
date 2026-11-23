/* cflags: @ee296 -O2 -G8 */
#include "common.h"

extern s32 func_01EEBEA4(s32, s32);

s32 func_01EEBD30(s32 arg0)
{
    s32 t;
    s32 vt;

    t = *(s32 *)(arg0 + 0x20);
    vt = *(s32 *)(t + 0x8);
    if ((*(s32 (**)(s32))((u8 *)vt + 0x28))(t) != 0) {
        vt = *(s32 *)arg0;
        if ((*(s32 (**)(s32))((u8 *)vt + 0x4C))(arg0) != 0)
            return func_01EEBEA4(arg0, 7);
        func_01EEBEA4(arg0, 0xA);
    }
}
