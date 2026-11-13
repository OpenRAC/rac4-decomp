/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern s32 func_01EFCD54(s32);
s32 func_01EFD1AC(s8 *arg0, u32 arg1, u32 arg2) {
    s32 ok = 1;
    u32 i;
    if (arg1 >= arg2) {
        for (i = 0; i < arg2 && ok; i++) {
            if (func_01EFCD54(arg0[i]) != 4) {
                ok = 0;
            }
        }
    }
    return ok;
}
