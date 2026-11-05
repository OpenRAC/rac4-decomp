/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s32 func_00541FB8(void);
s32 func_00541FD8(void);
s32 func_11EDA0(s32);
void func_L00_004F84C8(s32, s32, s32, s32, s32);
s32 func_L00_0053D010(s32, s32, s32);

/* Opens a menu entry by kind, reporting an error when the lookup fails. */
s32 func_L00_0053CF50(s32 arg0, s32 arg1, s32 arg2, s64 arg3) {
    s32 result = 0;
    if (arg1 == 1) {
        if (arg3 == 3) {
            result = func_L00_0053D010(arg0, func_00541FB8(), 1);
            if (result == 0) {
                func_L00_004F84C8(0xB, 0xD6, 0x9D, 0, 0);
            } else {
                result = func_L00_0053D010(arg0, func_11EDA0(func_00541FD8()), 1);
            }
        } else {
            result = func_L00_0053D010(arg0, arg2, arg3);
        }
    }
    return result != 0;
}
