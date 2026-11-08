/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_L00_004F0220(s32);
s32 func_L00_004F08A0(s32);
s32 func_L00_005131E0(s32, s32, s32);

s32 func_L00_00513308(s32 arg0, s32 arg1, s32 arg2) {
    func_L00_004F08A0(arg2);
    func_L00_005131E0(arg0, arg1, arg2);
    func_L00_004F0220(arg2 + 4);
    return 0x28;
}
