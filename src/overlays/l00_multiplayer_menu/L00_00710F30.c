/* cflags: @ee29-01 -O2 -G0 */
#include "common.h"

extern s32 func_0069D408(s32);

s32 func_L00_00710F30(u8 *arg0, s32 arg1) {
    s32 v = *(s32 *)(arg0 + 0x14);

    if (v != 0) {
        *(s32 *)(arg0 + 0x5C) = arg1;
        if (arg1 != 0) {
            return func_0069D408(v);
        }
        return 1;
    }
    return 0;
}
