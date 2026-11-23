/* Not matching yet: PAL WIP; main .text 0x004F1668, 76B. Not part of the build. */
/*
 * Actual compiler reverses completion stores (zero0x221FF4 before one0x221FF0); unused native a0
 * setup and register/layout gaps remain.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: adf6ae1f54433e53e9cc2fb9d62cbc478e73bec2bd4de1403638ae041b857274
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004F1668 nonmatching/pal/game/func_004F1668.c --diff
 */
#include "common.h"

s32 func_00138D70(void);
extern int D_0021DE6C;
extern u32 D_PAL_00221FF0;
extern u32 D_PAL_00221FF4;

void func_004F1668(s32 expectedWord) {
    s32 helperWord;
    s32 capturedState;

    do {
        helperWord = func_00138D70();
        capturedState = D_0021DE6C;
    } while (helperWord == expectedWord && capturedState == 0);

    D_PAL_00221FF0 = 1;
    D_PAL_00221FF4 = 0;
}
