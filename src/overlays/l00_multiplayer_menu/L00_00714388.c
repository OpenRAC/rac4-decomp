#include "common.h"

extern u8 D_004B8D68[];
s32 func_L00_00710750();
s32 func_L00_00714400();

s64 func_L00_00714388(char *arg0, s32 arg1) {
    func_L00_00710750(arg0);
    *(s32 *)(arg0 + 88) = (s32)D_004B8D68;
    func_L00_00714400(arg0, arg1);
    return (s32)arg0;
}
