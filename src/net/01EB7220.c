/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EBE188(s32 p, s32 out, s32 other);
extern s32 func_01EBE0F0(s32 p, s32 out, s32 other);

s32 func_01EB7220(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 ret;
    if (arg0 == NULL) return 2;
    if (arg1 == 0) {
        ret = func_01EBE188(*arg0, arg2, arg3);
        if (ret != 0) return ret;
    } else if (arg1 == 1) {
        ret = func_01EBE0F0(*arg0, arg2, arg3);
        if (ret != 0) return ret;
    } else {
        return 2;
    }
    return 0;
}
