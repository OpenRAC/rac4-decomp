/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

s32 func_004C0A58(void *); /* extern */
s32 func_004C1320(void *); /* extern */
s32 func_00506BB8();       /* extern */
extern u8 D_0030B358[];

void func_004C09B0(void) {
    s32 temp_3_2;
    s32 temp_4;
    void *temp_16;
    void *temp_3;
    void *temp_4_2;
    u32 var_2;
    temp_16 = ((u32)func_00506BB8() * 0x258U) + D_0030B358;
    temp_3 = (void *)(((unsigned char *)temp_16) + 492);
    if ((*((s32 *)(((u8 *)temp_3) + 0x50))) > 0) {
        temp_4 = *((s32 *)(((u8 *)temp_3) + 0x54));
        if (temp_4 < 0) {
            var_2 = 0;
        } else {
            var_2 = *((u32 *)(((u8 *)temp_3) + 0x34)) + ((u32)temp_4 * 0x18U);
        }
        temp_4_2 = *((void **)(var_2 + 8));
        temp_3_2 = *((s32 *)(((u8 *)temp_4_2) + 8));
        if (temp_3_2 == 0) {
            func_004C0A58(temp_4_2);
        } else if (temp_3_2 == 1) {
            func_004C1320(temp_4_2);
        }
    }
    *((s32 *)(((u8 *)temp_16) + 4)) = (s32)((*((s32 *)(((u8 *)temp_16) + 4))) & (~4));
}
