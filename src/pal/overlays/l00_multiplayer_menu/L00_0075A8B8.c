/* cflags: @ee29 -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
#include "common.h"

extern s16 func_L00_005C9580(void);
extern s32 D_0022168C;

s32 func_L00_0075A8B8(void) {
    s32 result;
    if (func_L00_005C9580() == 2) {
        D_0022168C = result = 6;
    } else {
        D_0022168C = result = 7;
    }
    return result;
}
