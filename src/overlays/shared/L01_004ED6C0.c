#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_L01_004E9E20(s32, u128, u8, s32, s32);
extern u8 D_1F1400[];

// Set two timers in D_1F1400 to 3, then pass the linked record's fields to func_L01_004E9E20 when it has one.
void func_L01_004ED6C0(void *arg0, s32 arg1, s32 arg2) {
    u8 *temp_a0;
    u8 *temp_v1;
    void *temp_v0;

    temp_a0 = *(u8 **)((u8 *)arg0 + 0x18);
    temp_v1 = D_1F1400;
    *(s16 *)(temp_v1 + 0x1E60) = 3;
    *(s16 *)(temp_v1 + 0x531C) = 3;
    temp_v0 = *(void **)(temp_a0 + 0x2EF4);
    if (temp_v0 != NULL) {
        func_L01_004E9E20(*(s32 *)((u8 *)temp_v0 + 0x2B0), *(u128 *)((u8 *)arg0 + 0x40), *((u8 *)arg0 + 0x7), arg2, *(s32 *)((u8 *)arg0 + 0x30));
    }
}
