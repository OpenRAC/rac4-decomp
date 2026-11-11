/* cflags: @ee29 -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
#include "common.h"

extern s16 func_L00_005C82E0(void);
extern s32 D_002215CC;

s32 func_L00_00755A20(void) {
    s32 result;
    if (func_L00_005C82E0() == 2) {
        D_002215CC = result = 6;
    } else {
        D_002215CC = result = 7;
    }
    return result;
}
