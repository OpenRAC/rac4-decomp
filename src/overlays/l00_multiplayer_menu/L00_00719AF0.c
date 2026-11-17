#include "common.h"

extern void func_00739B20(void *);
extern void func_L00_00719880(void *arg0, s32 arg1, s32 arg2);

/* Sets the 0xA8 object's mode byte and two floats, then sends event 0x11. */
s32 func_L00_00719AF0(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    u8 *o = *(u8 **)((u8 *)arg0 + 0xA8);

    if (o != 0) {
        func_00739B20(o);
        *(s8 *)(o + 0x26C) = arg2;
        *(f32 *)(o + 0xE64) = arg4;
        *(f32 *)(o + 0xE68) = arg5;
        func_L00_00719880(arg0, 0x11, arg3);
        return *(s32 *)(o + 0x264);
    }
    return -1;
}
