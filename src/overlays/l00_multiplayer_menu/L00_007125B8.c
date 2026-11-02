#include "common.h"

extern u8 D_004B8700[];
s32 func_L00_00710750();
s32 func_L00_00712630();

s64 func_L00_007125B8(char *arg0, s32 arg1) {
    func_L00_00710750(arg0);
    *(s32 *)(arg0 + 88) = (s32)D_004B8700;
    func_L00_00712630(arg0, arg1);
    return (s32)arg0;
}
