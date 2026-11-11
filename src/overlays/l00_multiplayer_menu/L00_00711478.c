#include "common.h"

extern s32 func_L00_0069E7A8(s32 item, s32 mode);
extern s32 func_L00_0069E6E0(s32 item, f32 first, f32 second);

s32 func_L00_00711478(void *object, s32 mode, f32 first, f32 second)
{
    s32 item;

    item = *(s32 *)((s8 *)object + 0x14);
    if (item != 0) {
        if (func_L00_0069E7A8(item, mode) != 0) {
            if (mode != 0) {
                return func_L00_0069E6E0(*(s32 *)((s8 *)object + 0x14), first, second);
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
