/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01F0A2FC(s32);
s32 func_01F0A63C(s32);
extern s32 D_0016E664[];

s32 func_01F0A5F0(void) {
    s32 temp_v0;

    if (D_0016E664[0] == 0) {
        temp_v0 = func_01F0A63C(0x214);
        func_01F0A2FC(temp_v0);
        D_0016E664[0] = temp_v0;
    }
    return D_0016E664[0];
}
