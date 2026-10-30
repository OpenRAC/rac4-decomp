#include "common.h"

extern void func_00158C60(s32, s32, void *, s32, s32);

/* Copies its first six arguments into a buffer, then calls func_00158C60 with 0x11, 0x18, the buffer and the last two arguments. */
void func_00158780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 buf[6];

    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = arg2;
    buf[3] = arg3;
    buf[4] = arg4;
    buf[5] = arg5;
    func_00158C60(0x11, 0x18, buf, arg6, arg7);
}
