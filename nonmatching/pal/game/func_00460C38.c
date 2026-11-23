/* Not matching yet: PAL WIP; main .text 0x00460C38, 80B. Not part of the build. */
/*
 * All seven ordinary forms emit HI16/LO16 for D0021EF98; native begins with one GP-relative LW at
 * effective221EF98. No alias/global definition/profile trick was attempted.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 99d7a1d438bc60b34fb23a807a22978ac616a0d07f2aababb1c5361421285927
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00460C38 nonmatching/pal/game/func_00460C38.c --diff
 */
#include "common.h"

extern s32 D_0021EF98;
extern s32 D_003D7EF8[];

s32 func_00460C38(s32 key)
{
    s32 count = D_0021EF98;
    s32 result = 0;
    s32 index = 0;

    if (index < count) {
        s32 *record = D_003D7EF8;
        do {
            if (record[0] == key) {
                result = record[1];
            }
            record += 4;
            index++;
            if (result != 0) {
                break;
            }
        } while (index < count);
    }
    return result;
}
