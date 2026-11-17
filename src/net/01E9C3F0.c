/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01E9C240(s32, s32, s32 *);
extern s32 func_01E9C338(s32, s32, s32, s32);
s32 func_01E9C3F0(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 r = func_01E9C240(arg0, arg1, arg2);
    if (r < 0) {
        return r;
    }
    r = func_01E9C338(arg0, arg1, *arg2, arg4);
    if (r >= 0) {
        r = 0;
    }
    return r;
}
