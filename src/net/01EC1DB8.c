/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EBD5C8(s32);
s32 func_01EBD678(s32, s32, s32);

void func_01EC1DB8(s32 arg0, s32 arg1, s32 arg2) {
    func_01EBD678(arg0, arg1, func_01EBD5C8(arg2));
}
