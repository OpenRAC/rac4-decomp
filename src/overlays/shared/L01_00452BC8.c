#include "common.h"
s32 func_L01_00452698();                        /* extern */

void func_L01_00452BC8(void *arg0) {
    void *temp_s0;

    temp_s0 = (*(void **)((u8 *)(arg0) + 0xAC));
    if ((*(u8 *)((u8 *)(arg0) + 0x20)) == 0) {
        func_L01_00452698();
    }
    (*(s8 *)((u8 *)(temp_s0) + 0x12)) = 0;
}
