#include "common.h"
void func_L00_007493B8(void *arg0, s32 arg1) {
    void *temp_a0;
    void *temp_a0_2;

    temp_a0 = (*(void **)((u8 *)(arg0) + 0xB0));
    (*(s32 (**)(void *))((u8 *)((*(void **)((u8 *)(temp_a0) + 0x58))) + 0x28))(temp_a0);
    temp_a0_2 = (*(void **)((u8 *)(arg0) + 0xB0));
    (*(s32 (**)(void *, s32))((u8 *)((*(void **)((u8 *)(temp_a0_2) + 0x58))) + 0xE8))(temp_a0_2, arg1);
}
