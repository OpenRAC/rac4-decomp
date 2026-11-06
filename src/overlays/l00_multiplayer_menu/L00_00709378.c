#include "common.h"
s32 func_L00_00709A50();                            /* extern */

void func_L00_00709378(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_L00_00709A50();
    if ((temp_v0 != 0) && (arg1 < 2)) {
        (*(s8 *)((u8 *)((temp_v0 + arg1)) + 4)) = 1;
    }
}
