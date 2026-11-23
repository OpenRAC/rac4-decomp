/* Not matching yet: PAL WIP; main net.text 0x01EC1DF8, 468B. Not part of the build. */
/*
 * Default plain C emits412B versus native468B; compatible source effect repair is not a match.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 6a43e1c7f87adae28222d685f5ba91ae9c448a9163257384175cebaca1322b7c
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EC1DF8 nonmatching/pal/net/func_01EC1DF8.c --diff
 */
#include "common.h"

/* Classify the two-byte packet flags and sequence against context state. */
u16 func_01EBD5C8(u8 *a0);

s32 func_01EC1DF8(void *arg0, u8 *arg1, s32 *arg2) {
    u16 sp0;
    u8 sp1;
    u16 sp2;
    u8 sp3;
    s16 temp_v0_2;
    s32 var_v0;
    u16 temp_s2;
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_v1;
    u16 temp_v1_2;
    u8 *temp_a1;
    void *var_s0;

    var_v0 = 2;
    *arg2 = 0;
    if (arg0 != NULL) {
        sp0 = (*(u8 *)((s8 *)(arg1) + (0)));
        sp1 = (*(u8 *)((s8 *)(arg1) + (1)));
        temp_v0 = (u16) (sp0 | (sp1 << 8)) & 0xF800;
        sp0 = temp_v0;
        if ((*(s32 *)((s8 *)(arg0) + (0))) != 0) {
            if (temp_v0 & 0x4000) {
                temp_s2 = func_01EBD5C8(arg1);
                temp_v1 = (*(u16 *)((s8 *)(arg0) + (0x68)));
                if (temp_v1 >= 0x7FFFU) {
                    if ((temp_v1 - 0x7FFF) < (s32) temp_s2) {
                        if (temp_v1 < temp_s2) {
                            goto block_15;
                        }
                        goto block_13;
                    }
                    goto block_15;
                }
                if (temp_v1 < temp_s2) {
                    if (((*(u16 *)((s8 *)(arg0) + (0x68))) + 0x7FFF) >= (s32) temp_s2) {
block_15:
                        var_s0 = NULL;
                        temp_a1 = (u8 *)arg0 + 0x24;
                        if (temp_a1 != NULL) {
                            var_s0 = *(void **)(temp_a1 + 0xC);
                        }
loop_20:
                        var_v0 = 0;
                        if (var_s0 != NULL) {
                            temp_a1 = (u8 *)var_s0 + 8;
                            if ((*(s32 *)((s8 *)(var_s0) + (0))) != 0) {
                                sp2 = (*(u8 *)((s8 *)(var_s0) + (8)));
                                sp3 = (*(u8 *)((s8 *)(temp_a1) + (1)));
                                temp_v0_2 = (u16) (sp2 | (sp3 << 8)) & 0xF800;
                                sp2 = temp_v0_2;
                                if ((sp0 & 0x4000) && (temp_v0_2 & 0x4000) && (temp_s2 == func_01EBD5C8(temp_a1))) {
                                    *arg2 = 1;
                                    goto block_31;
                                }
                            }
                            var_s0 = (*(void **)((s8 *)(var_s0) + (4)));
                            goto loop_20;
                        }
                        /* Duplicate return node #32. Try simplifying control flow for better match */
                        return var_v0;
                    }
                    goto block_13;
                }
block_13:
                *arg2 = 1;
                return 0;
            }
            var_v0 = 0;
            if (sp0 & 0x2000) {
                temp_s2 = func_01EBD5C8(arg1);
                temp_v1_2 = (*(u16 *)((s8 *)(arg0) + (0x66)));
                if (!((temp_v1_2 - temp_s2) & 0x8000) && (*arg2 = 1, (((u32) (temp_v1_2 & 0xFFFF) < 0x7FFFU) != 0))) {
                    var_v0 = 0;
                    if (func_01EBD5C8(arg1) & 0x8000) {
                        temp_v0_3 = func_01EBD5C8(arg1);
                        *arg2 = 0;
                        (*(u16 *)((s8 *)(arg0) + (0x66))) = temp_v0_3;
                        goto block_31;
                    }
                } else {
                    goto block_31;
                }
            }
            /* Duplicate return node #32. Try simplifying control flow for better match */
            return var_v0;
        }
block_31:
        var_v0 = 0;
        /* Duplicate return node #32. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
