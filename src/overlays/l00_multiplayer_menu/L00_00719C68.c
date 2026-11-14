#include "common.h"

extern void func_L00_00719880(void *arg0, s32 arg1, s32 arg2);
extern void func_L00_007493B8(void *arg0, s32 arg1);
extern void func_L00_00749408(u8 *owner, const u32 *input, s32 count);

/* Updates the 0xBC object's fields around two calls, then returns its 0x668 value or -1. */
s32 func_L00_00719C68(void *arg0, s32 arg1, const u32 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    u8 *o = *(u8 **)((u8 *)arg0 + 0xBC);
    u8 saved;

    if (arg3 > 0 && o != 0) {
        func_L00_007493B8(o, arg1);
        func_L00_00749408(o, arg2, arg3);
        saved = o[0x674];
        *(s32 *)(o + 0x668) = arg4;
        o[0x674] = (u8)arg6;
        func_L00_00719880(arg0, 0x16, arg5);
        o[0x674] = saved;
        if (o[0x66C] == 0) {
            return *(s32 *)(o + 0x668);
        }
        return -1;
    }
    return -1;
}
