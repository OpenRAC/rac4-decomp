#include "common.h"

extern void func_0054B288(void *, s32, s32, s32);
extern s32 func_00549398(void *, s32);
extern s32 func_00549368(void *, s32);
extern void func_00549330(void *, s32, s32);

s32 func_0054BA08(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *pointer;
    s32 offset;
    s32 result;
    s32 other;
    s32 i;

    if ((u32)(arg2 - 1) >= 8) {
        return 0;
    }
    offset = arg1 * 0x44;
    pointer = (u8 *)arg0 + offset;
    for (i = 0; i < 0xA; i++, pointer += 4) {
        if (pointer[0xA44] == arg2) {
            pointer[0xA44] = 0;
            if (arg3 != 0) {
                func_0054B288(arg0, arg2, -1, 0);
            }
            if (arg2 == 2) {
                result = func_00549398(arg0, arg1);
                other = func_00549368(arg0, arg1);
                if (result < other) {
                    func_00549330(arg0, arg1, result);
                }
            }
            return 1;
        }
    }
    return 0;
}
