/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_1B7258[];
extern s32 *D_00167EFC[];
s32 *func_01EC8EA8(void *, s32);
extern s32 func_01ECB358(s32, s32, s32);
void func_01ECB548(s32, void *, s32);

// Walks the list at D_1B7258 + 0x12C and queues or flushes each entry that has no slot yet.
void func_01ECC808(void) {
    s32 *temp_v0;
    s32 temp_a0;
    s32 temp_v1;
    s32 var_s0;
    u32 temp_s3;
    u8 *temp_s2;
    u8 *var_s1;
    u8 *base;

    base = D_1B7258;
    temp_s2 = *(u8 **)(base + 0x138);
    if (temp_s2 != NULL) {
        temp_s3 = *(u32 *)(temp_s2 + 0x404);
        if (temp_s3 < 0x100U) {
            var_s1 = *(u8 **)(base + 0x12C);
            if (var_s1 != NULL) {
                do {
                    temp_a0 = *(s32 *)(var_s1 + 0x3C);
                    if (temp_a0 == 0) {
                        func_01ECB548(-1, var_s1, 1);
                    } else {
                        temp_v1 = *(s32 *)(var_s1 + 0x38);
                        if (temp_v1 != 0 && (u32)(temp_a0 + temp_v1) < (u32)D_00167EFC[0][4]) {
                            func_01ECB548(-1, var_s1, 0);
                        } else {
                            var_s0 = 0;
                            if (*(s32 *)(temp_s2 + 0x460) > 0) {
                                do {
                                    temp_v0 = func_01EC8EA8(temp_s2, var_s0);
                                    if (temp_v0 != NULL && var_s0 != (s32)temp_s3 && ((s32 *)*(s32 **)(var_s1 + 0x40))[var_s0] == 0 && *temp_v0 != 0) {
                                        func_01ECB548(var_s0, var_s1, 1);
                                    }
                                    var_s0 += 1;
                                } while (var_s0 < *(s32 *)(temp_s2 + 0x460));
                            }
                            func_01ECB358((s32)var_s1, 0, 0);
                        }
                    }
                    var_s1 = *(u8 **)(var_s1 + 0x4C);
                } while (var_s1 != NULL);
            }
        }
    }
}
