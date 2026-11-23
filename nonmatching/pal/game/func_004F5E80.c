/* Not matching yet: PAL WIP; main .text 0x004F5E80, 84B. Not part of the build. */
/*
 * h02/h03 recover BEQL fill-arm SW(-1), copy LW/SW, periteration byte-clear,
 * signed16-loop/wordpointer/inputstride structure; register/color/base initialization differ from
 * native.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 6282abb788eef0a90b83560faed87cad4b14e3b0d41929844ed43096d27bd8a2
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_004F5E80 nonmatching/pal/game/func_004F5E80.c --diff
 */
#include "common.h"
extern s32 D_00328950_pal_words[];
extern u8 D_00222020_pal_bytes[];
extern s32 D_00220A1C_pal_mode;
extern s32 D_00220A18_pal_count;

void func_004F5E80(s32 count, s32 *input, s32 mode)
{
    s32 i;
    for (i = 0; i < 16; i++) {
        if (i < count) {
            D_00328950_pal_words[i] = input[i];
        } else {
            D_00328950_pal_words[i] = -1;
        }
        D_00222020_pal_bytes[i] = 0;
    }
    D_00220A1C_pal_mode = mode;
    D_00220A18_pal_count = count;
}
