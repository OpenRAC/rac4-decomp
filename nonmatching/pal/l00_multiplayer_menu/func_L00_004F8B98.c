/* Not matching yet: PAL WIP; level_00 .text 0x004F8B98, 24B. Not part of the build. */
/*
 * Defined full64 projection/indexing retained, but signed projection and shift/mask/control
 * scheduling differ from native. No result-type or register forcing is included.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: f61d8015f8ea2943fb10a8e118bb1e1f2f70c8964c14ae802d44c50c89faaa35
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_L00_004F8B98 nonmatching/pal/l00_multiplayer_menu/func_L00_004F8B98.c --diff
 */
#include "common.h"

/* Returns the sign-extended low word of a modulo-64 difference. */
s64 func_L00_004F8B98(s64 *arg0, s64 *arg1) {
    u64 leftBits = *(u64 *)arg0;
    u64 rightBits = *(u64 *)arg1;

    return (s64)(s32)(u32)(leftBits - rightBits);
}
