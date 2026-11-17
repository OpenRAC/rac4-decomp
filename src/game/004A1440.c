#include "common.h"

extern void func_00501638(s32 *group, s32 type, s32 owner);
extern s32 func_00504F68(u32 id, s32 enabled);
extern s32 func_00505DD0(u32 id, s32 amount);

// Inserts a 0x18-byte entry at slot arg2 (or the end), shifting later entries up, and updates the cursor and flags.
void func_004A1440(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0_2;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    u8 *temp_a0;
    u8 *temp_v0;
    u8 *temp_v1;

    var_s1 = arg2;
    if (var_s1 < 0) {
        var_s1 = *(s32 *)((u8 *)arg0 + 0x50);
    }
    temp_v0 = (u8 *)(*(s32 *)((u8 *)arg0 + 0x50) * 0x18 + *(s32 *)((u8 *)arg0 + 0x34));
    if (*(u8 *)(temp_v0 + 0xD) == 0) {
        *(u8 *)(temp_v0 + 0xD) = 1;
        func_00501638((s32 *)(*(s32 *)((u8 *)arg0 + 0x34) + *(s32 *)((u8 *)arg0 + 0x50) * 0x18 + 4), *(s32 *)((u8 *)arg0 + 0x3C), -1);
        func_00505DD0(*(s32 *)((u8 *)arg0 + 0x2C) + 2, *(s32 *)(*(s32 *)((u8 *)arg0 + 0x50) * 0x18 + *(s32 *)((u8 *)arg0 + 0x34) + 4));
    }
    func_00504F68(*(s32 *)(*(s32 *)((u8 *)arg0 + 0x50) * 0x18 + *(s32 *)((u8 *)arg0 + 0x34) + 4), 1);
    var_a3 = *(s32 *)((u8 *)arg0 + 0x50);
    if (var_s1 < var_a3) {
        var_a2 = var_a3 * 0x18;
        do {
            var_a3 -= 1;
            temp_a0 = (u8 *)(var_a2 + *(s32 *)((u8 *)arg0 + 0x34));
            *(u8 *)temp_a0 = *(u8 *)(temp_a0 - 0x18);
            temp_v1 = (u8 *)(var_a2 + *(s32 *)((u8 *)arg0 + 0x34));
            *(s32 *)(temp_v1 + 8) = *(s32 *)(temp_v1 - 0x10);
            *(u8 *)(var_a2 + *(s32 *)((u8 *)arg0 + 0x34) + 0xC) = 1;
            var_a2 -= 0x18;
        } while (var_s1 < var_a3);
    }
    temp_v1_2 = var_s1 * 0x18;
    *(u8 *)(temp_v1_2 + *(s32 *)((u8 *)arg0 + 0x34)) = 1;
    *(s32 *)(temp_v1_2 + *(s32 *)((u8 *)arg0 + 0x34) + 8) = arg1;
    *(u8 *)(temp_v1_2 + *(s32 *)((u8 *)arg0 + 0x34) + 0xC) = 1;
    temp_a0_2 = *(s32 *)((u8 *)arg0 + 0x54);
    if (temp_a0_2 < 0) {
        *(s32 *)((u8 *)arg0 + 0x54) = 0;
    } else if (temp_a0_2 >= var_s1) {
        *(s32 *)((u8 *)arg0 + 0x54) = temp_a0_2 + 1;
    }
    *(s32 *)((u8 *)arg0 + 0x50) = *(s32 *)((u8 *)arg0 + 0x50) + 1;
    *(s32 *)((u8 *)arg0 + 0x58) = *(s32 *)((u8 *)arg0 + 0x58) | 3;
}
