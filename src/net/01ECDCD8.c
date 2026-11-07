/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EC9CB0(u16);

s32 func_01ECDCD8(s32 arg0, s32 arg1, s32 arg2, u16 *arg3) {
    func_01EC9CB0(*arg3);
    return 2;
}
