/* Not matching yet: PAL WIP; main .text 0x004C0708, 384B. Not part of the build. */
/*
 * Register roles row=s2/kind=s0/result=s1 differ from native row=s0/kind=s1/result=s2; mode reject
 * synthesizes -1 rather than copying saved result.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: a5f25316223e72014a3d8df6f45e16872b502bff4d1dbc8df11509aeff786eea
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004C0708 nonmatching/pal/game/func_004C0708.c --diff
 */
#include "common.h"

extern char D_0030B358[];
extern s32 D_0021F218;
extern s32 D_0021DE98;




s32 func_004BF020(s32);                             
s32 func_004BFA60(u32);                             
s32 func_00505B20(void);                                

/* Keep the first eligible hit on one arm and the last selected hit on the other. */
s32 func_004C0708(void) {
    u8 *temp_s0;
    s32 temp_s1;
    s32 selected;
    s32 predicateStatus;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a2;
    s32 var_s2;
    s32 var_v0;
    u32 var_v1;
    u32 var_v1_2;
    u8 *temp_v0;
    u8 *temp_v1_4;
    u8 *temp_v1_7;
    u8 *var_v0_2;
    u8 *var_v0_3;

    var_s2 = -1;
    temp_s0 = (u8 *)D_0030B358 + (u32)func_00505B20() * 0x258U;
    selected = D_0021F218;
    temp_s1 = func_004BFA60(selected);
    temp_v1 = D_0021DE98;
    if ((temp_v1 == 1) || (var_v0 = -1, (temp_v1 == 0x15))) {
        predicateStatus = func_004BF020(temp_s1);
        temp_v0 = temp_s0 + 0x1EC;
        if (predicateStatus != 0) {
            var_a2 = 1;
            temp_v1_2 = (*(s32 *)((s8 *)(temp_v0) + (0x50)));
            var_a0 = 0;
            if (temp_v1_2 > 0) {
                do {
                    if (var_a0 < 0) {
                        temp_v1_3 = (*(s32 *)((s8 *)(temp_v0) + (0x54)));
                        var_v1 = (u32)temp_v1_3 * 0x18U;
                        if (temp_v1_3 < 0) {
                            var_v0_2 = NULL;
                        } else {
                            goto block_9;
                        }
                    } else {
                        var_v1 = (u32)var_a0 * 0x18U;
block_9:
                        var_v0_2 = (*(u8 **)((s8 *)(temp_v0) + (0x34))) + var_v1;
                    }
                    temp_v1_4 = (*(u8 **)((s8 *)(var_v0_2) + (8)));
                    if (((*(u8 *)((s8 *)(temp_v1_4) + (2))) != 0) && ((*(u8 *)((s8 *)(temp_v1_4) + (0))) == 0) && (var_a2 != 0)) {
                        var_s2 = var_a0;
                        var_a2 = 0;
                    }
                    var_a0 += 1;
                } while (var_a0 < temp_v1_2);
                return var_s2;
            }
            goto block_26;
        }
        var_a0_2 = 0;
        temp_v1_5 = (*(s32 *)((s8 *)(temp_v0) + (0x50)));
        if (temp_v1_5 > 0) {
            do {
                if (var_a0_2 < 0) {
                    temp_v1_6 = (*(s32 *)((s8 *)(temp_v0) + (0x54)));
                    var_v1_2 = (u32)temp_v1_6 * 0x18U;
                    if (temp_v1_6 < 0) {
                        var_v0_3 = NULL;
                    } else {
                        goto block_22;
                    }
                } else {
                    var_v1_2 = (u32)var_a0_2 * 0x18U;
block_22:
                    var_v0_3 = (*(u8 **)((s8 *)(temp_v0) + (0x34))) + var_v1_2;
                }
                temp_v1_7 = (*(u8 **)((s8 *)(var_v0_3) + (8)));
                if ((*(s32 *)((s8 *)(temp_v1_7) + (8))) == 1) {
                    var_s2 = (((*(s32 *)((s8 *)(temp_v1_7) + (4))) ^ temp_s1) == 0) ? var_a0_2 : var_s2;
                }
                var_a0_2 += 1;
            } while (var_a0_2 < temp_v1_5);
        }
block_26:
        var_v0 = var_s2;
        
        return var_v0;
    }
    return var_v0;
}
