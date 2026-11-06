#include "common.h"

extern void func_L00_005F1778(s32, u8 *, s32);

void func_L01_0050F848(u8 *arg0, u8 *arg1) {
    s32 v;

    v = *(s32 *)(arg1 + 0x10);
    if (v != 0) {
        func_L00_005F1778(v, arg1 + 0x30, 0);
    }
}
