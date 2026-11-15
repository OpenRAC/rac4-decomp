/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 352 / disc 356.
 * Function text: 352 B; native catalogue: 356 B; 14 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L00_005C48C8 nonmatching/pal/shared/func_L00_005C48C8.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */


s32 func_0047C548(void *);                          /* extern */
void *func_00511EB8(void *);                        /* extern */
s32 func_00540A00(void *, s32);                     /* extern */
extern s32 D_0021E734;

s32 func_L00_005C48C8(void *arg0, void *arg1) {
    s16 temp_v1;
    s16 temp_v1_2;
    s32 temp_a1;
    s32 var_v0;
    u8 temp_a0;
    void *temp_s1;
    void *temp_v0;

    temp_v1 = (*(s16 *)((s8 *)(arg1) + (0xBC)));
    if (temp_v1 != 0x210D) {
        if (((*(u8 *)((s8 *)(arg1) + (0x31))) != 0) && (temp_v1 != 0x19C0) && (temp_v1 != 0x1AE6) && (temp_v1 != 0x244B)) {
            var_v0 = 0;
            if (temp_v1 != 0x209A) {
                var_v0 = 0;
                if (arg1 != (*(s32 *)((s8 *)(arg0) + (0xBC)))) {
                    var_v0 = 0;
                    if ((*(u16 *)((s8 *)(arg1) + (0x34))) & 0x1000) {
                        if ((*(void **)((s8 *)(arg1) + (0x24))) != NULL) {
                            temp_s1 = (*(void **)((s8 *)(arg0) + (0x130)));
                            temp_v0 = func_00511EB8(arg1);
                            if ((temp_v0 == NULL) || (D_0021E734 != 1) || (var_v0 = 0, ((*(s32 (**)(void *, s32))((s8 *)((*(void **)((s8 *)(temp_v0) + (0x14)))) + (0x1C)))(temp_v0, (*(s32 *)((s8 *)(temp_s1) + (0x2F14)))) == 0))) {
                                temp_a1 = func_0047C548(arg1);
                                temp_a0 = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg1) + (0x24)))) + (0x46)));
                                if ((temp_a0 == 5) || (temp_a1 == 0x40) || ((temp_a0 == 0x11) && ((temp_v1_2 = (*(s16 *)((s8 *)(arg1) + (0xBC))), (temp_v1_2 == 0x2077)) || (temp_v1_2 == 0x253A)) && (temp_s1 != NULL) && ((*(s32 *)((s8 *)(temp_s1) + (0x2318))) == 0xD))) {
                                    goto block_19;
                                }
                                if (((*(u8 *)((s8 *)((*(void **)((s8 *)(arg1) + (0x24)))) + (0x46))) != 0xD) || (var_v0 = 1, (func_00540A00(arg1, (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x130)))) + (0x2F14)))) == 0))) {
                                    goto block_22;
                                }
                                /* Duplicate return node #23. Try simplifying control flow for better match */
                                return var_v0;
                            }
                            /* Duplicate return node #23. Try simplifying control flow for better match */
                            return var_v0;
                        }
                        goto block_22;
                    }
                }
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        }
block_22:
        var_v0 = 0;
        return var_v0;
    }
block_19:
    return 1;
}
