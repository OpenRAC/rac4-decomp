/* Not matching yet: PAL WIP; level_00 .text 0x005C2078, 428B. Not part of the build. */
/*
 * Still424B versus native428B. Output/masked-value registers, branch-delay constant allocation,
 * final branch extent and six-byte arm store scheduling differ. Unsigned byte representation is
 * not the sole mismatch; no new supported distinction justifies another trial.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: d13f2cf27bcf9482eafd6cb4b08fbcdc56e194ffee8fe6d015c8db92c1229de0
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_005C2078 nonmatching/pal/l00_multiplayer_menu/func_L00_005C2078.c --diff
 */
#include "common.h"

/* Encode the captured two source bytes into a terminated byte sequence. */
void func_L00_005C2078(void *arg0, void *arg1)
{
    u8 *input = arg0;
    u8 *output = arg1;
    u8 high;
    u8 low;
    s32 value;
    u32 masked;

    high = input[0];
    low = input[1];
    value = (high << 8) | low;
    masked = value & 0xFFFF;
    if (masked < 0x80U) {
        output[1] = 0;
        output[0] = (u8)(value & 0x7F);
        return;
    }
    if ((u32)(masked - 0x80) < 0x780U) {
        output[1] = (u8)((value & 0x3F) | 0x80);
        output[0] = (u8)(((masked >> 6) & 0x1F) | 0xC0);
        output[2] = 0;
        return;
    }
    if ((u32)(masked - 0x800) <= 0xF7FFU) {
        output[0] = (u8)((masked >> 0xC) | 0xE0);
        output[1] = (u8)(((masked >> 6) & 0x3F) | 0x80);
        output[2] = (u8)((value & 0x3F) | 0x80);
        output[3] = 0;
        return;
    }
    if ((u32)(masked + 0xFFFF0000U) <= 0x1EFFFFU) {
        output[0] = 0xF0;
        output[1] = (u8)((masked >> 0xC) | 0x80);
        output[2] = (u8)(((masked >> 6) & 0x3F) | 0x80);
        output[3] = (u8)((value & 0x3F) | 0x80);
        output[4] = 0;
        return;
    }
    if ((u32)(masked + 0xFFE00000U) <= 0x03DFFFFFU) {
        output[0] = 0xF8;
        output[1] = 0x80;
        output[2] = (u8)((masked >> 0xC) | 0x80);
        output[3] = (u8)(((masked >> 6) & 0x3F) | 0x80);
        output[4] = (u8)((value & 0x3F) | 0x80);
        output[5] = 0;
        return;
    }
    if ((u32)(masked + 0xFC000000U) <= 0x7BFFFFFFU) {
        output[0] = 0xFC;
        output[1] = 0x80;
        output[2] = 0x80;
        output[3] = (u8)((masked >> 0xC) | 0x80);
        output[4] = (u8)(((masked >> 6) & 0x3F) | 0x80);
        output[5] = (u8)((value & 0x3F) | 0x80);
        output[6] = 0;
    }
}
