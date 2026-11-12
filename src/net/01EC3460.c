/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern s32 func_01EA9E28(void *, s32);
extern s32 D_00169554;
extern s32 D_001B69C0[];

s32 func_01EC3460(void) {
    s32 ret;

    ret = 5;
    if (D_00169554 != 0) {
        ret = func_01EA9E28(D_001B69C0, 0);
    }
    return ret;
}
