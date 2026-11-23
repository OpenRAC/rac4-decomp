/* Not matching yet: PAL WIP; main net.text 0x01EC97D0, 136B. Not part of the build. */
/*
 * Every source family remains different in loop/return/allocation/scheduling; none emits native
 * four-NOP gap01EC981C..9828 between nextword load9818 and likelybranch982C. t02 closestsize124B
 * has different earlyresultzero/LUI/loop branch graph. HI/LO forms resolve actual167FB8 and
 * R26callee01EC98E8 correctly but bytes remain inexact. GP forms issue R_MIPS_GPREL16
 * D00167FB8__gp for a cell far outside residentGP signed16r
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 637d28eaf66e50ac7bab0a63cccd775e165d9fd778c6d2acae643de12650c2c9
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EC97D0 nonmatching/pal/net/func_01EC97D0.c --diff
 */
#include "common.h"

extern u8 *D_00167FB8;
s32 func_01EC98E8(u32 index);

s32 func_01EC97D0(u32 index)
{
    s32 node = func_01EC98E8(index);
    if (node != 0) {
        u8 *context = D_00167FB8;
        s32 current = *(s32 *)(context + 0x12C);
        if (current == 0) {
            *(s32 *)(context + 0x12C) = node;
            *(s32 *)((u8 *)node + 0x4C) = 0;
            current = *(s32 *)(context + 0x12C);
        }
        while (current != 0) {
            s32 next;
            if (current == node)
                break;
            next = *(s32 *)((u8 *)current + 0x4C);
            if (next == 0) {
                *(s32 *)((u8 *)current + 0x4C) = node;
                *(s32 *)((u8 *)node + 0x4C) = 0;
                break;
            }
            current = next;
        }
    }
    return 0;
}
