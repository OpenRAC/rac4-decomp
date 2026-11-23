/* Not matching yet: PAL WIP; level_00 .text 0x00670E18, 124B. Not part of the build. */
/*
 * Candidate uses valid boundLUI0x22/LW-0x998 to realownedL00flag21F668; native uses
 * validGP2259FF-relativeLW-0x6397. This addsoneinstruction/4B; wholebytes nonexact.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: b57f571706d69d0c604286fe813b6c67a0bb6c6f12ca90828f70fb9aed8c4da7
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_00670E18 nonmatching/pal/shared/func_L00_00670E18.c --diff
 */
#include "common.h"

extern s32 D_PAL_L00_0021F668;
extern u8 D_001D2280[];

void func_L00_00670E18(s32 object, s32 first, s32 value, s32 second, s32 third)
{
    if (D_PAL_L00_0021F668 != 0) {
        u8 current = D_001D2280[0x40];
        *(s32 *)(D_001D2280 + 0x2A8) = object;
        if (current != first) {
            u8 flags = D_001D2280[0x43];
            D_001D2280[0x40] = (u8)first;
            D_001D2280[0x43] = (u8)(flags | 1);
        }
        if (*(s32 *)(D_001D2280 + 0x2AC) != value) {
            u8 flags = D_001D2280[0x43];
            *(s32 *)(D_001D2280 + 0x2AC) = value;
            D_001D2280[0x43] = (u8)(flags | 4);
        }
        if (D_001D2280[0x41] != second || D_001D2280[0x42] != third) {
            u8 flags = D_001D2280[0x43];
            D_001D2280[0x42] = (u8)third;
            D_001D2280[0x41] = (u8)second;
            D_001D2280[0x43] = (u8)(flags | 2);
        }
    }
}
