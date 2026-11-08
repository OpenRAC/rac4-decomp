#include "common.h"

s32 func_L00_006A1EC0(s32 handle, f32 value0, f32 value1);
s32 func_L00_006A1F88(s32 handle, s32 flag);

s32 func_L00_00715298(void *object, s32 flag, f32 value0, f32 value1)
{
    s32 handle;

    handle = *(s32 *)((u8 *)object + 0x14);
    if (handle != 0) {
        if (func_L00_006A1F88(handle, flag) != 0) {
            if (flag != 0) {
                return func_L00_006A1EC0(*(s32 *)((u8 *)object + 0x14), value0, value1);
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
