/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EF2C94(s32);
s32 func_01EF2DB8(s32);
extern s32 D_0016E498[];

s32 func_01EF2CC4(void) {
    s32 temp_v0;

    if (D_0016E498[0] == 0) {
        temp_v0 = func_01EF2DB8(0x204);
        func_01EF2C94(temp_v0);
        D_0016E498[0] = temp_v0;
    }
    return D_0016E498[0];
}
