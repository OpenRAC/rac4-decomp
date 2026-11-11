/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_L00_00566EC0();
s32 func_L00_00566EE0(s32);
extern s32 D_004A9BB0[];

void *func_L00_00567138(void) {
    s32 temp_v0;

    temp_v0 = func_L00_00566EE0(1);
    if (temp_v0 == 0) {
        return D_004A9BB0;
    }
    func_L00_00566EC0();
    return temp_v0 + 16;
}
