/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_00126BB0(s32);
s32 func_0013A7A0(s32, s32, s32);
extern s32 D_00167BFC[];
extern s32 D_00167C00[];

s32 func_0013A0F0(void) {
    if (D_00167BFC[0] >= 0) {
        func_0013A7A0(0, 0, 0);
        func_00126BB0(D_00167BFC[0]);
        D_00167BFC[0] = -1;
        func_00126BB0(D_00167C00[0]);
    }
    return 1;
}
