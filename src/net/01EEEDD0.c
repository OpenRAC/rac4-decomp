/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

s32 func_01EEEE20(s32);
s32 func_01EEFE94(s32);
extern s32 D_0016E430;

void func_01EEEDD0(s32 arg0, s32 arg1) {
    if (D_0016E430 != 0) {
        func_01EEEE20(arg0);
        if (arg1 != 0) {
            func_01EEFE94(arg0);
        }
    }
}
