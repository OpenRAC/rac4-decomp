#include "common.h"

extern s32 func_L00_005DB000(s32, void *);
extern void func_L00_005D1AB8(s32, s32, s32, s32, s32);

// Rounds arg3 up to 64 bytes, reserves the block and returns the bytes left over
s32 func_L00_005D1A18(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 size;
    s32 left;

    left = 0;
    if (arg3 != 0) {
        size = arg3 + func_L00_005DB000(arg1, arg3);
        size = (size + 0x3F) & 0xFFFFFFC0;
        left = func_L00_005DB000(arg2, size) + (size - arg3);
        arg2 = size;
        arg1 = arg3;
    }
    func_L00_005D1AB8(arg0, arg1, arg2, 0, 0);
    return left;
}
