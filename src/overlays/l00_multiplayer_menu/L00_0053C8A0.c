/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_00541FA8();
extern s32 func_00541FC8();
extern s32 func_11EDA0(s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_0053CA88(s32, s32, s32);

/* Dispatches a menu event to func_L00_0053CA88, with a special path for kind 3. */
s32 func_L00_0053C8A0(void *arg0, s32 arg1, s32 arg2, s64 arg3) {
    s32 obj = *(s32 *)((u8 *)arg0 + 0xC);
    s32 ret = 0;
    if (arg1 == 2) {
        if (arg3 == 3) {
            ret = func_L00_0053CA88(obj, func_00541FA8(), 1);
            if (ret == 0) {
                func_L00_004F84C8(0xB, 0xD7, 0x9C, 0, 0);
            } else {
                ret = func_L00_0053CA88(obj, func_11EDA0(func_00541FC8()), 1);
            }
        } else {
            ret = func_L00_0053CA88(obj, arg2, arg3);
        }
    }
    return ret;
}
