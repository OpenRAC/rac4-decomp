#include "common.h"

// Set or clear bits in a 16-bit flag register.
void func_0050EF28(void *arg0, s32 arg1, s32 arg2) {
    void *temp_a0;
    void *temp_v1;
    u16 temp_v0;

    if (arg2 != 0) {
        temp_v1 = *(void **)(arg0 + 0x40);
        temp_v0 = *(u16 *)(temp_v1 + 0x40) | (u16)arg1;
        *(u16 *)(temp_v1 + 0x40) = temp_v0;
    } else {
        temp_a0 = *(void **)(arg0 + 0x40);
        temp_v0 = *(u16 *)(temp_a0 + 0x40) & ~(u16)arg1;
        *(u16 *)(temp_a0 + 0x40) = temp_v0;
    }
    *(u8 *)(arg0 + 0x44) = 1;
}
