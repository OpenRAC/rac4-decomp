/* Not matching yet: PAL WIP; main .text 0x0040D948, 572B. Not part of the build. */
/*
 * Continuation byte capture before count store repaired. Native result/error case joins, redundant
 * byte-code normalization and scheduling remain; chosen original captured-u8 draft avoids later
 * read-coalescing/type experiments.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 64e17baeae5b6be9def1ed8765c21162e9e0b026fa84994bf167a82e4ed810bc
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_0040D948 nonmatching/pal/game/func_0040D948.c --diff
 */
#include "common.h"



s32 func_0040D948(u32 *arg0, s32 *arg1, s32 *arg2, void *arg3, u8 *arg4, u32 arg5) {
    s32 temp_a7;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1_2;
    s32 var_v0;
    u32 var_v0_2;
    u8 temp_v0_3;
    u8 temp_v1;
    u8 continuation;
    s8 lengthByte;
    u8 *temp_a1;
    u8 *temp_a6;
    u8 *var_a0;

    var_v0 = 0x800;
    if (arg5 != 0) {
        *arg1 = (s32) *arg4;
        *arg2 = 0;
        if ((*arg1 & 0x1F) == 0x1F) {
loop_3:
            temp_v0 = *arg2;
            if (arg5 >= ((u32)temp_v0 + 2U)) {
                continuation = *(u8 *)((arg4 + temp_v0) + 1);
                *arg2 = (s32)((u32)temp_v0 + 1U);
                if (!(continuation & 0x80)) {
                    goto block_5;
                }
                goto loop_3;
            }
            return 0x800;
        }
block_5:
        temp_a7 = *arg2;
        var_v0 = 0x800;
        if (arg5 >= ((u32)temp_a7 + 2U)) {
            temp_a1 = arg4 + temp_a7;
            temp_a6 = temp_a1 + 1;
            lengthByte = *(s8 *)(temp_a1 + 1);
            temp_v1 = *(u8 *)(temp_a1 + 1);
            if (lengthByte >= 0) {
                temp_v0_2 = temp_v1 & 0xFF;
                var_a0 = temp_a1 + 2;
                (*(s32 *)((s8 *)(arg3) + (4))) = temp_v0_2;
                var_v0_2 = (u32)temp_v0_2 + (u32)*arg2 + 2U;
                goto block_21;
            }
            temp_v1_2 = temp_v1 & 0xFF;
            if (temp_v1_2 == 0x80) {
                var_v0 = 0x801;
                if (*arg1 & 0x20) {
                    (*(s32 *)((s8 *)(arg3) + (4))) = 0;
                    (*(void **)((s8 *)(arg3) + (0))) = (void *) (temp_a1 + 2);
                    *arg0 = 0;
block_32:
                    var_v0 = (arg5 < (u32) *arg0) << 0xB;
                }
                
                return var_v0;
            } else if (temp_v1_2 == 0x81) {
                var_v0 = 0x800;
                if (arg5 >= ((u32)temp_a7 + 3U)) {
                    temp_v0_3 = (*(u8 *)((s8 *)(temp_a6) + (1)));
                    var_a0 = temp_a1 + 3;
                    (*(s32 *)((s8 *)(arg3) + (4))) = (s32) temp_v0_3;
                    var_v0_2 = (u32)temp_v0_3 + (u32)*arg2 + 3U;
block_21:
                    *arg0 = var_v0_2;
                    (*(void **)((s8 *)(arg3) + (0))) = var_a0;
                    goto block_32;
                }
                
                return var_v0;
            } else if (temp_v1_2 == 0x82) {
                var_v0 = 0x800;
                if (arg5 >= ((u32)temp_a7 + 4U)) {
                    var_a0 = temp_a1 + 4;
                    temp_v0_4 = ((*(u8 *)((s8 *)(temp_a6) + (1))) << 8) | (*(u8 *)((s8 *)(temp_a6) + (2)));
                    (*(s32 *)((s8 *)(arg3) + (4))) = temp_v0_4;
                    var_v0_2 = (u32)temp_v0_4 + (u32)*arg2 + 4U;
                    goto block_21;
                }
                
                return var_v0;
            } else if (temp_v1_2 == 0x83) {
                var_v0 = 0x800;
                if (arg5 >= ((u32)temp_a7 + 5U)) {
                    temp_v0_5 = ((*(u8 *)((s8 *)(temp_a6) + (1))) << 0x10) | ((*(u8 *)((s8 *)(temp_a6) + (2))) << 8) | (*(u8 *)((s8 *)(temp_a6) + (3)));
                    (*(s32 *)((s8 *)(arg3) + (4))) = temp_v0_5;
                    *arg0 = (u32)temp_v0_5 + (u32)*arg2 + 5U;
                    (*(void **)((s8 *)(arg3) + (0))) = (void *) (temp_a1 + 5);
                    goto block_32;
                }
                
                return var_v0;
            } else if (temp_v1_2 == 0x84) {
                var_v0 = 0x800;
                if (arg5 >= ((u32)temp_a7 + 6U)) {
                    temp_v0_6 = ((u32)(*(u8 *)((s8 *)(temp_a6) + (1))) << 0x18) | (*(u8 *)((s8 *)(temp_a6) + (4))) | (((*(u8 *)((s8 *)(temp_a6) + (3))) << 8) | ((*(u8 *)((s8 *)(temp_a6) + (2))) << 0x10));
                    (*(s32 *)((s8 *)(arg3) + (4))) = temp_v0_6;
                    *arg0 = (u32)temp_v0_6 + (u32)*arg2 + 6U;
                    (*(void **)((s8 *)(arg3) + (0))) = (void *) (temp_a1 + 6);
                    goto block_32;
                }
                
                return var_v0;
            } else {
                return 0x801;
            }
        } else {
            
            return var_v0;
        }
    } else {
        return var_v0;
    }
}
