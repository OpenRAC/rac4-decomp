/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 *D_00167F30;
extern s32 func_01EA57B8(s32, s32);
extern s32 func_01EA42D8(s32);
extern s32 func_01EA57F8(void);

s32 func_01E9EA88(s32 arg0, s32 arg1)
{
    s32 first = func_01EA57B8(arg0, arg1);
    s32 status = func_01EA42D8(first);
    if (status == 0) {
        s32 (*callback)(s32, s32) = *(s32 (**)(s32, s32))(D_00167F30 + 0x40);
        s32 created = callback(arg0, arg1);
        s32 next = func_01EA57F8();
        s32 other = func_01EA42D8(next);
        return other == 0 ? created : other;
    }
    return status;
}
