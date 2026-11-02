#include "common.h"

extern u8 D_004B8B40[];
s32 func_L00_00710750();
s32 func_L00_007134B8();

s64 func_L00_00713440(char *arg0, s32 arg1) {
    func_L00_00710750(arg0);
    *(s32 *)(arg0 + 88) = (s32)D_004B8B40;
    func_L00_007134B8(arg0, arg1);
    return (s32)arg0;
}
