#include "common.h"

extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);

// When the byte at +0x20 is zero, set +0x30 to 0xFF, clear the +4 word of the linked record, clamp its +0 word and call func_L01_00591BD8.
void func_L02_004CF4C8(u8 *arg0) {
    s32 temp_v0;
    u8 temp_v1;
    u8 *temp_t0;

    temp_v1 = arg0[0x20];
    temp_t0 = *(u8 **)(arg0 + 0xAC);
    if (temp_v1 == 0) {
        arg0[0x30] = 0xFF;
        *(s32 *)(temp_t0 + 4) = 0;
        temp_v0 = *(s32 *)temp_t0;
        if ((s32)temp_v1 >= temp_v0) {
            temp_v0 = 1;
        }
        *(s32 *)temp_t0 = temp_v0;
        func_L01_00591BD8(arg0, 1, -1);
    }
}
