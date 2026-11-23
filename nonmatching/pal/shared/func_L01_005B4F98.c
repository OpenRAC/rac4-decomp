/* Not matching yet: PAL WIP; level_01 .text 0x005B4F98, 184B. Not part of the build. */
/*
 * Compiled200B/native184B. Narrow formal signnormalisation atentry and SD/LD0x50frame remain
 * versus native SQ/LQ0x90frame. Packed arithmetic/argallocation differs. Actualcompiled
 * ninthentry-stackword LW+7C occursafterobjectflagSH+78 butBEFORE node byte16SB+80; native
 * ninthLW+80 occursAFTER byte16/15/17, word48, half4C stores. Compiled half4Estore+84
 * occursbeforebyte15/17/word48/half4C/word44; nativehalf4E islast at+88.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 9939ca8229792bff79440bb4476ff912a99f0464147740ec8e65a6ddc71dc514
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_005B4F98 nonmatching/pal/shared/func_L01_005B4F98.c --diff
 */
#include "common.h"

/* Automatischer m2c-Grobentwurf, kein geprÃ¼fter Match.
 * Unbekannte M2C_* und saved_reg_* mÃ¼ssen manuell aufgelÃ¶st werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prÃ¼fen.
 */


s32 func_00476F40(void *);                              /* extern */

void func_L01_005B4F98(void *arg0, s8 arg1, s8 arg2, s32 arg3, s16 arg4, s32 arg5, s32 arg6, s8 arg7, s32 arg_sp0) {
    u8 *temp_v0;

    temp_v0 = (u8 *)func_00476F40(arg0);
    if (temp_v0 != NULL) {
        (*(u16 *)((s8 *)(arg0) + (0x34))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x34))) & 0xFFFD);
        (*(s8 *)((s8 *)(temp_v0) + (0x16))) = arg7;
        (*(s8 *)((s8 *)(temp_v0) + (0x15))) = arg1;
        (*(s8 *)((s8 *)(temp_v0) + (0x17))) = arg2;
        (*(s32 *)((s8 *)(temp_v0) + (0x48))) = arg3;
        (*(s16 *)((s8 *)(temp_v0) + (0x4C))) = arg4;
        (*(s32 *)((s8 *)(temp_v0) + (0x44))) = (s32) ((arg5 & 0xFFFF) | (arg6 << 0x10));
        (*(s16 *)((s8 *)(temp_v0) + (0x4E))) = (s16) arg_sp0;
    }
}
