#include "common.h"

extern s32 func_004C6868(void);
extern s32 func_004C6968(s32 arg0);
extern s32 func_00505B20(void);
extern s32 D_0021F198;
extern char D_1F87F0[];
extern char D_30B9D8[];
extern char D_30D038[];

// Finds the index of the first matching entry in the table for the current slot; returns it, or -1.
s32 func_004C6970(void) {
    char *var_a3;
    char *temp_v1;
    char *temp_s2;
    char *var_v0;
    char *temp_v1_3;
    u8 *temp_v0_3;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_s1;
    s32 idx;
    s32 var_a0;
    s32 i;
    s32 var_s3;
    s32 var_s4;
    s32 var_t0;

    var_s3 = -1;
    var_s4 = -1;
    temp_s2 = (func_00505B20() * 0xB30) + D_30B9D8;
    temp_s1 = func_004C6868();
    temp_s0 = D_0021F198;
    if (func_004C6968(temp_s0) != 0) {
        var_a3 = temp_s2 + 0xAB4;
        temp_v1 = D_30D038 + temp_s1 * 0x34;
        var_t0 = 1;
        for (i = 0; i < *(s32 *)(temp_v1 + 4); i++) {
            if (var_t0 != 0) {
                temp_a0_2 = ((s32 *)(temp_v1 + 8))[i];
                temp_v0_3 = D_1F87F0 + temp_a0_2 * 0xC;
                if (temp_v0_3[9] == 0) {
                    var_s4 = temp_a0_2;
                    var_t0 = 0;
                }
            }
        }
    } else {
        var_s4 = temp_s0;
        var_a3 = temp_s2 + 0xAB4;
    }
    for (var_a0 = 0; var_a0 < *(s32 *)(var_a3 + 0x50); var_a0++) {
        if (var_s3 == -1) {
            idx = var_a0;
            if (idx < 0) {
                idx = *(s32 *)(var_a3 + 0x54);
            }
            if (idx < 0) {
                var_v0 = NULL;
            } else {
                var_v0 = *(char **)(var_a3 + 0x34) + idx * 0x18;
            }
            temp_v1_3 = *(char **)(var_v0 + 8);
            if (*(s32 *)(temp_v1_3 + 8) != 1) {
                var_s3 = ((*(s32 *)(temp_v1_3 + 4) ^ var_s4) == 0) ? var_a0 : var_s3;
            }
        }
    }
    return var_s3;
}
