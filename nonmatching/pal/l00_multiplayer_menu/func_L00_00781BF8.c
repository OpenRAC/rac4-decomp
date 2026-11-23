/* Not matching yet: PAL WIP; level_00 .text 0x00781BF8, 316B. Not part of the build. */
/*
 * Float/word element indexing repaired; native mismatch-only likely branch, pointer copies,
 * context pointer-read scheduling and result join remain different. Actual288B/native316B, with
 * real owned table binding only.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: acaac694dbdaf48c7962f523986fea0ade679d888af48304ea00d03f26e8f5d6
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_00781BF8 nonmatching/pal/l00_multiplayer_menu/func_L00_00781BF8.c --diff
 */
#include "common.h"
#include "pal/global_002234A4.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_L00_00781BF8(s32 arg0) {
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a6;
    s32 var_a6_2;
    s32 var_v1;
    void **temp_v0_2;
    void **temp_v0_4;
    void *temp_a0;
    void *temp_a5;
    void *temp_v1;
    s32 *fallback_key;
    void *var_a0;
    void *var_a3;
    void *var_v1_2;
    void *var_v1_3;

    temp_v1 = D_002234A4;
    var_a6 = 0;
    var_a3 = NULL;
    temp_a0 = (*(void **)((s8 *)(temp_v1) + (0x3C)));
    fallback_key = (*(s32 **)((s8 *)(temp_v1) + (0x34)));
    temp_a5 = (*(void **)((s8 *)(temp_v1) + (0x38)));
    if ((*(u8 *)((s8 *)(temp_a0) + (0x3D0))) != 0) {
        temp_v1_2 = (*(s32 *)((s8 *)(temp_a0) + (0x3D4)));
        if (temp_v1_2 >= 0) {
            var_a3 = (s8 *)temp_a0 + ((temp_v1_2 * 0xC) + 0x3E8);
        }
    }
    if (var_a3 != NULL) {
        temp_v0 = (*(s32 *)((s8 *)(var_a3) + (4)));
        var_a1 = 0;
        if (temp_v0 > 0) {
            temp_v0_2 = (*(void ***)((s8 *)(var_a3) + (8)));
            var_v1_2 = *temp_v0_2;
loop_8:
            if ((*(s32 *)((s8 *)(var_v1_2) + (0x1C))) != arg0) {
                var_a1 += 1;
                if (var_a1 < temp_v0) {
                    var_v1_2 = temp_v0_2[var_a1];
                    goto loop_8;
                }
            } else {
                var_a6 = 1;
            }
        }
    }
    var_a0 = NULL;
    var_a6_2 = 0;
    if ((*(u8 *)((s8 *)(temp_a5) + (0))) != 0) {
        temp_v1_3 = (*(s32 *)((s8 *)(temp_a5) + (4)));
        if (temp_v1_3 >= 0) {
            var_a0 = (s8 *)temp_a5 + ((temp_v1_3 * 0xC) + 0x28);
        }
    }
    if (var_a0 != NULL) {
        temp_v0_3 = (*(s32 *)((s8 *)(var_a0) + (4)));
        var_a1_2 = 0;
        if (temp_v0_3 > 0) {
            temp_v0_4 = (*(void ***)((s8 *)(var_a0) + (8)));
            var_v1_3 = *temp_v0_4;
loop_21:
            if ((*(s32 *)((s8 *)(var_v1_3) + (0x1C))) != arg0) {
                var_a1_2 += 1;
                if (var_a1_2 < temp_v0_3) {
                    var_v1_3 = temp_v0_4[var_a1_2];
                    goto loop_21;
                }
            } else {
                var_a6_2 = 1;
            }
        }
    }
    if (var_a6 != 0) {
        var_v1 = (var_a6_2 != 0) ? 3 : 2;
    } else {
        var_v1 = 1;
        if (var_a6_2 == 0) {
            var_v1 = ((arg0 ^ *fallback_key) != 0) ? 0 : 3;
        }
    }
    return var_v1;
}
