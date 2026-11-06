#include "common.h"

extern s32 func_L00_006A1230(s32 handle, f32 a, f32 b);

s32 func_L00_0071B5B8(void *object, f32 a, f32 b)
{
    s32 handle = *(s32 *)((u8 *)object + 0x5C);
    if (handle == 0) {
        handle = *(s32 *)((u8 *)object + 0x134);
        if (handle == -1)
            return 0;
    }
    return func_L00_006A1230(handle, a, b);
}
