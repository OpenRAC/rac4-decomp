/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EA57B8(s32, s32);
extern s32 func_01EA42D8(s32);
extern s32 func_01EC9B08(s32, s32);
extern s32 func_01EA57F8(void);

s32 func_01EC9730(s32 arg0, s32 arg1)
{
    s32 first = func_01EA57B8(arg0, arg1);
    s32 status = func_01EA42D8(first);
    if (status == 0) {
        s32 created = func_01EC9B08(arg0, arg1);
        s32 next = func_01EA57F8();
        s32 other = func_01EA42D8(next);
        return other == 0 ? created : other;
    }
    return status;
}
