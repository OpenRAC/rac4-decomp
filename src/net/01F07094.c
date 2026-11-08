/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01F07100();
s32 func_01F07198(s32, s32, s32);

void func_01F07094(s32 arg0, s32 arg1) {
    func_01F07198(func_01F07100(), arg0, arg1);
}
