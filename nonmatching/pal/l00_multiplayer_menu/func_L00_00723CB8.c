/* Not matching yet: PAL WIP; level_00 .text 0x00723CB8, 68B. Not part of the build. */
/*
 *  0x0024 lw $a0, -0x4C2B($gp) | lw $v1, -0x4C2B($gp) 0x0034 sw $v0, 0x118($a0) | addiu $a0,
 * $zero, 0x1 0x0038 addiu $a0, $zero, 0x1 | sw $v0, 0x118($v1)
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: a0d9f3ff9cd2eac570c4cc7ba44b4b851c67a4cb1734e07e5be5336820a45d6e
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_00723CB8 nonmatching/pal/l00_multiplayer_menu/func_L00_00723CB8.c --diff
 */
#include "common.h"
#include "pal/global_002234A4.h"

struct Context;
extern struct Context *D_00220DD4;

s32 func_L00_00723CB8(void)
{
    u8 *row = *(u8 **)((u8 *)D_002234A4 + 0x3C);
    s32 result = 0;

    if (row[0x30] == 0) {
        s32 value = *(s32 *)row;
        struct Context *context = D_00220DD4;
        switch (value) {
        case -1:
            *(s32 *)((u8 *)context + 0x118) = 7;
            break;
        default:
            *(s32 *)((u8 *)context + 0x118) = 5;
            break;
        }
        result = 1;
    }
    return result;
}
