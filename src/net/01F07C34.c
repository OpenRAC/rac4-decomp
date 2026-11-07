/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01F07750(s32);
s32 func_01F07C80(s32);
extern s32 D_0016E658[];

s32 func_01F07C34(void) {
    s32 temp_v0;

    if (D_0016E658[0] == 0) {
        temp_v0 = func_01F07C80(8);
        func_01F07750(temp_v0);
        D_0016E658[0] = temp_v0;
    }
    return D_0016E658[0];
}
