#include "common.h"

extern u8 D_004B7E78[];
s32 func_L00_00710750();
void func_L00_00711120();

s64 func_L00_007110A8(char *arg0, s32 arg1) {
    func_L00_00710750(arg0);
    *(s32 *)(arg0 + 88) = (s32)D_004B7E78;
    func_L00_00711120(arg0, arg1);
    return (s32)arg0;
}
