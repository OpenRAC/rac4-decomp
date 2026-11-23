/* Additional metadata limitation: US006A9748:96 contains separately mapped US006A9778:48 at+0x30; its source is the continuation loop helper, whereas the PAL96B owned WIP includes state/first-element handling. This retained PAL WIP is not compiled or mapped as a match. No US extent, alias, cross-version independence, complete ABI, or matched-code credit is certified. */
/* Not matching yet: PAL WIP; level_00 .text 0x006ACF68, 96B. Not part of the build. */
/*
 * Native zero-initializes index before firstelement and later increments; t03 initializes1
 * afterfirstmiss. Native saveskeya0intoa2 and higharraybaseintoa3; t03 keepskeya0/basea2. Native
 * baseadd beforeSLL2 vs t03 SLL2 in boundbranchdelay beforebaseadd.
 * Bothreadsamewords/storefirstmatch; native96B,t03 88B,notexact. t01/t02 100Bstillpointercursor
 * loop. Full literalinstruction diffs retained perresult.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: cabe0b88973f32fc549db587255f4d0d3935fb1c97a099bea21da1b7dab015c1
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_006ACF68 nonmatching/pal/shared/func_L00_006ACF68.c --diff
 */
#include "common.h"

extern s32 D_0021E734;
extern s32 D_002448C0[];

void func_L00_006ACF68(s32 key) {
    s32 *entry;
    s32 i;

    if (D_0021E734 == 1) {
        if (D_002448C0[0] == key) {
            D_002448C0[0] = 0;
            return;
        }
        i = 1;
scan:
        if (i < 0x100) {
            entry = &D_002448C0[i];
            i++;
            if (*entry == key) {
                *entry = 0;
            } else {
                goto scan;
            }
        }
    }
}
