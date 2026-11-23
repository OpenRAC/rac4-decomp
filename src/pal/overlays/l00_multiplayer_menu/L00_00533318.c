#include "common.h"

extern char D_004A2FA8[];

s32 func_L00_00533318(s32 arg0)
{
    s32 result = 0;

    if (arg0 != 0) {
        if (*(s32 *)((s8 *)arg0 + 0x2C) == arg0 && *(s32 *)((s8 *)arg0 + 0x28) == (s32)D_004A2FA8) {
            arg0 = 0;
        } else {
            arg0 = 0x212;
        }
        result = arg0;
    }
    return result;
}
