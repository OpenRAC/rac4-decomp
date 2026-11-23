/* Not matching yet: PAL WIP; main net.text 0x01EBF100, 72B. Not part of the build. */
/*
 *  0x0004 addiu $a2, $zero, 0x2 | daddu $a3, $a1, $zero 0x0008 beqz $a0, . + 4 + (0xB << 2) | sd
 * $ra, 0x0($sp) 0x000C sd $ra, 0x0($sp) | beqz $a0, . + 4 + (0xB << 2) 0x0010 beqz $a1, . + 4 +
 * (0x9 << 2) | addiu $v0, $zero, 0x2 0x0014 ori $a2, $zero, 0xD2F3 | beqz $a3, . + 4 + (0x9 << 2)
 * 0x0018 lw $v1, 0x0($a1) | ori $v0, $zero, 0xD2F3 0x001C addiu $v0, $zero, 0x8 | lw $a2, 0x0($a3)
 * 0x0020 bne $v1, $v0, . + 4 + (0x5 << 2
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: d922eccde7d2b93db5d92c2b9e8078f17ea74f9e7e04042fb5fee3efebf50a26
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EBF100 nonmatching/pal/net/func_01EBF100.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprüfter Match.
 * Unbekannte M2C_* und saved_reg_* müssen manuell aufgelöst werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prüfen.
 */
s32 func_01EC1D40(s32 *a, char *b);

s32 func_01EBF100(s32 *arg0, s8 *arg1) {
    s32 var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        var_v0 = 0xD2F3;
        if (arg1 != NULL) {
            var_v0 = 0xD2F4;
            if (*(s32 *)arg1 == 8) {
                *(s32 *)arg1 = 5;
                func_01EC1D40(arg0, arg1);
                var_v0 = 0;
            }
        }
    }
    return var_v0;
}
