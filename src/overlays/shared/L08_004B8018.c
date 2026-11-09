#include "common.h"

extern s32 func_L01_00591BD8(s32, s32, s32);
extern s32 D_00222694;

void func_L08_004B8018(u8 *arg0) {
    s32 *p = (s32 *)(*(u8 **)(arg0 + 0xAC) + 0x10);
    s32 i;

    for (i = 5; i >= 0; i--) {
        func_L01_00591BD8(D_00222694 + (*p << 8), 1, -1);
        p++;
    }
}
