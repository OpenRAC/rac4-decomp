#include "common.h"

extern s32 func_L00_00553C68(void *, void *, s32);
extern s32 func_L00_00553D58(void *, void *, s32);

/* selector 0 and 1 call a helper on the spilled argument block; any other selector returns 2 */
s32 func_L00_00553DC8(void *a0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_v0;
    s32 buf[3];
    s32 temp_v0;

    buf[0] = arg2;
    buf[1] = arg3;
    buf[2] = arg4;
    if (arg1 == 0) {
        temp_v0 = func_L00_00553C68(a0, buf, 3);
        if (temp_v0 != 0) {
            return temp_v0;
        }
        goto block_5;
    }
    if (arg1 == 1) {
        var_v0 = func_L00_00553D58(a0, buf, 3);
        if (var_v0 == 0) {
block_5:
            var_v0 = 0;
        }
    } else {
        var_v0 = 2;
    }
    return var_v0;
}
