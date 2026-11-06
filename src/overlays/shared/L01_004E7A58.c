#include "common.h"
s32 func_0046BDD0(s32);                         /* extern */

void func_L01_004E7A58(void *arg0) {
    s32 temp_a0;
    void *temp_s0;

    temp_s0 = (*(void **)((u8 *)(arg0) + 0xAC));
    temp_a0 = (*(s32 *)((u8 *)(temp_s0) + 0x358));
    if (temp_a0 != 0) {
        func_0046BDD0(temp_a0);
        (*(s32 *)((u8 *)(temp_s0) + 0x358)) = 0;
    }
}
