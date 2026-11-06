#include "common.h"

extern void func_L01_00591BD8(u8 *, s32, s32);

s32 func_L01_00514D38(u8 *arg0) {
    if (*(u8 *)(arg0 + 0x20) != 0) {
        return 0;
    }
    func_L01_00591BD8(arg0, 1, -1);
    return 1;
}
