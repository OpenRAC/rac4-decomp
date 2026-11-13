/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_01EFCD54(s32);
s32 func_01EFCDF0(s8 *arg0, s32 arg1) {
    if (arg1 > 0) {
        arg1--;
        while (arg1 > 0 && func_01EFCD54(arg0[arg1]) == 4) {
            arg1--;
        }
    }
    return arg1;
}
