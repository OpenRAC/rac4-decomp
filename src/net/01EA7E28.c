/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EA8928();

s32 func_01EA7E28(s32 arg0, s32 *arg1) {
    *arg1 = 0;
    if (func_01EA8928() == 0) {
        return 2;
    }
    *arg1 = arg0 + 8;
    return 0;
}
