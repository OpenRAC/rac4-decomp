/* Not matching yet: PAL WIP; main net.text 0x01ED9C60, 64B. Not part of the build. */
/*
 *  0x0004 beq $a0, $v0, . + 4 + (0x7 << 2) | beq $a0, $v0, . + 4 + (0x9 << 2) 0x0008 sltiu $v0,
 * $a0, 0x3 | sltiu $v1, $a0, 0x3 0x000C bnez $v0, . + 4 + (0x7 << 2) | bnez $v1, . + 4 + (0xA <<
 * 2) 0x0010 sltiu $v0, $a0, 0x7 | nop 0x0014 beqz $v0, . + 4 + (0x5 << 2) | sltiu $v0, $a0, 0x7
 * 0x0018 sltiu $v0, $a1, 0x2 | beqz $v0, . + 4 + (0x7 << 2) 0x001C bnez $v0, . + 4 + (0x3 << 2) |
 * nop 0x0020 nop | sltiu $v0, $a1, 0x2 0x00
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 6caba46820c9f12719b0ddcc29a7b97b462a815a1d1ead4719dd3ed03bca5128
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01ED9C60 nonmatching/pal/net/func_01ED9C60.c --diff
 */
#include "common.h"

s32 func_01ED9C60(u32 arg0, u32 arg1) {
    if (arg0 == 3U) {
        return 1;
    }
    if (arg0 < 3U) {
        return 0;
    }
    if (arg0 >= 7U) {
        return 0;
    }
    if (arg1 < 2U) {
        return 0;
    }
    return 1;
}
