/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern int func_00126BA0();
extern s32 func_00126BE0(s32);
extern s32 D_004A9B90[];
extern s32 D_004B1020[];

// Open the handle in D_004A9B90 when it is unset, then return 0 if func_00126BE0 accepts it, else -1.
s32 func_L00_00566950(void) {
    s32 buf[6];
    s32 temp_v0;

    if (D_004A9B90[0] < 0) {
        buf[2] = 1;
        buf[5] = (s32)D_004B1020;
        buf[1] = 1;
        temp_v0 = func_00126BA0(buf);
        D_004A9B90[0] = temp_v0;
        if (temp_v0 < 0) {
            return -1;
        }
    }
    return (func_00126BE0(D_004A9B90[0]) > -1) ? 0 : -1;
}
