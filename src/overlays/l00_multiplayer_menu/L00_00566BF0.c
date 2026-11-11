/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_L00_005669C0();
s32 func_L00_005669E0(s32);
extern s32 D_004A9BAC[];

void *func_L00_00566BF0(void) {
    s32 temp_v0;

    temp_v0 = func_L00_005669E0(1);
    if (temp_v0 == 0) {
        return D_004A9BAC;
    }
    func_L00_005669C0();
    return temp_v0 + 0xC;
}
