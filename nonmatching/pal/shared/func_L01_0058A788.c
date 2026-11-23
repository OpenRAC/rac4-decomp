/* Additional metadata limitation: US005864C8:116 contains separately mapped US00586514:8 at+0x4C; that existing source only returns0, whereas PAL116B owned WIP contains selector/submode guards. This retained PAL WIP is not compiled or mapped as a match. No US extent, alias, cross-version independence, complete ABI, or matched-code credit is certified. */
/* Not matching yet: PAL WIP; level_01 .text 0x0058A788, 116B. Not part of the build. */
/*
 * Guarded selector/submode control and both reachable native NOPs arise naturally, but actual
 * LUI/LW replaces native GP-relative load. One extra address instruction and consequent branches
 * leave120B/native116B.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 5473674c357b2f69603f3054a552fec112b1887f206d2a62346260b53704fca4
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L01_0058A788 nonmatching/pal/shared/func_L01_0058A788.c --diff
 */
#include "common.h"

extern s32 D_0021DE98;
extern s32 D_0021EC58;

s32 func_L01_0058A788(void) {
    s32 selector;
    s32 submode;

    selector = D_0021DE98;
    if (selector == 1 || selector == 21) {
        submode = D_0021EC58;
        if (submode == 13 || submode == 17 || submode == 21 || submode == 28) {
            return 1;
        }
        return 0;
    }
    if (selector == 15 || selector == 35) {
        return 0;
    }
    return 1;
}
