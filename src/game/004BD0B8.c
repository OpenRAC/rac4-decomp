#include "common.h"

extern s32 func_00498918(s32, s32);

// Returns a colour code from the flag bytes at arg0[0], arg0[1] and arg0[2] and the flag arg1; calls func_00498918 with 4 and 3 in one case.
s32 func_004BD0B8(u8 *arg0, s32 arg1) {
    if (arg0[0] != 0) {
        return 0x80808080;
    }
    if (arg1 != 0) {
        return 0x80D0D0D0;
    }
    if (arg0[2] == 0) {
        return (arg0[1] == 0) ? 0x80808080 : 0x80D0D0D0;
    } else {
        return func_00498918(4, 3);
    }
}
