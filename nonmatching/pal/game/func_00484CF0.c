/* Not matching yet: PAL WIP; main .text 0x00484CF0, 444B. Not part of the build. */
/*
 * Two defined low6 count masks remain; actual current direct-mask elimination rejects DI count at
 * SI predicate. Guarded bases differ from native preloop computations; common output extent absent
 * in existing pins. No global compiler impossibility. All source/object/history/diagnostic
 * evidence preserved.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 1c871edd7ab958891304ed3d1e242c59da67c016e3696c9ad29092a6bf9ef19d
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00484CF0 nonmatching/pal/game/func_00484CF0.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


void func_00484CF0(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 var_f2;
    s32 var_a7;
    s64 *temp_a0;
    s64 *temp_a0_2;
    s64 *temp_a0_3;
    s64 *temp_a0_4;
    s64 *temp_v1;
    s64 *temp_v1_2;
    s64 *temp_v1_3;
    s64 temp_a1;
    s64 temp_v0;
    s32 var_a6;
    u64 var_a4;
    void *temp_a2;
    void *resource;

    var_a7 = 0;
    var_a6 = -1;
    var_f2 = 100000.0f;
    var_a4 = 0;
    resource = (*(void **)((s8 *)(arg0) + (0x24)));
    if ((*(u8 *)((s8 *)(resource) + (0xC))) != 0) {
        do {
            temp_a2 = (*(void **)((s8 *)((*(void **)((s8 *)((*(void **)((s8 *)((resource + ((s32)var_a4 * 4))) + (0x48)))) + (0x18)))) + (4)));
            if (temp_a2 != NULL) {
                s8 *base100 = (s8 *)arg1 + 0x100;
                s8 *base138 = (s8 *)arg1 + 0x138;
                s8 *base160 = (s8 *)arg1 + 0x160;
                s8 *base178 = (s8 *)arg1 + 0x178;
                s8 *base198 = (s8 *)arg1 + 0x198;
                s8 *base2A0 = (s8 *)arg1 + 0x2A0;
                if ((*(f32 *)((s8 *)(temp_a2) + (0x10))) != 0.0f) {
                    var_a7 = 1;
                }
                if ((*(u8 *)((s8 *)(temp_a2) + (4))) != 0) {

                } else {
                    temp_f0 = (*(f32 *)((s8 *)(temp_a2) + (0xC)));
                    if ((temp_f0 > 0.0f) && (temp_f0 < var_f2)) {
                        var_f2 = temp_f0;
                        var_a6 = (s32)var_a4;
                    }
                }
                temp_a1 = (u64)1 << ((s32)var_a4 & 63);
                temp_a0 = arg1 + ((*(u8 *)((s8 *)(temp_a2) + (5))) * 8);
                *temp_a0 |= temp_a1;
                temp_v1 = base100 + ((*(u8 *)((s8 *)(temp_a2) + (6))) * 8);
                *temp_v1 |= temp_a1;
                temp_a0_2 = base138 + ((*(u8 *)((s8 *)(temp_a2) + (0))) * 8);
                *temp_a0_2 |= temp_a1;
                temp_v1_2 = base160 + ((*(u8 *)((s8 *)(temp_a2) + (3))) * 8);
                *temp_v1_2 |= temp_a1;
                temp_a0_3 = base178 + ((*(u8 *)((s8 *)(temp_a2) + (4))) * 8);
                *temp_a0_3 |= temp_a1;
                temp_v1_3 = base198 + ((*(u8 *)((s8 *)(temp_a2) + (7))) * 8);
                *temp_v1_3 |= temp_a1;
                temp_a0_4 = base2A0 + ((*(u8 *)((s8 *)(temp_a2) + (1))) * 8);
                *temp_a0_4 |= temp_a1;
            }
            resource = (*(void **)((s8 *)(arg0) + (0x24)));
            var_a4 += 1;
        } while (var_a4 < (u8) (*(u8 *)((s8 *)(resource) + (0xC))));
    }
    if ((var_a7 == 0) && (var_a6 != -1)) {
        (*(s64 *)((s8 *)(arg1) + (0x160))) = (s64) ((*(s64 *)((s8 *)(arg1) + (0x160))) | (((u64)1 << ((u64)var_a6 & 63))));
    }
}
