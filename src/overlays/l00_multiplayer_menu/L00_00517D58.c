#include "common.h"

extern void func_L00_0051A4D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

// Forwards the field at 0x1C of arg0 and arguments 1 to 4 to func_L00_0051A4D0, then returns 0.
s32 func_L00_00517D58(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_L00_0051A4D0((*(s32 *)((u8 *)(arg0) + 0x1C)), arg3, arg4, arg1, arg2);
    return 0;
}
