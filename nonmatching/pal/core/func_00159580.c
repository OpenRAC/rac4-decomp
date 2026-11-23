/* Not matching yet: PAL WIP; main core.text 0x00159580, 56B. Not part of the build. */
/*
 * Retained source defines a zero-initialized resident word. It is non-built WIP only; this
 * packaging does not approve canonical data ownership or a production definition.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: a968fa8e6f0f159e7cbfff5641665034e5d0e99a84d23bfffb10e92605f16c7a
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00159580 nonmatching/pal/core/func_00159580.c --diff
 */
#include "common.h"

s32 D_0021DD3C = 0;
extern s32 D_001C2000[];
s32 func_00137FB0(void);

s32 func_00159580(void)
{
    if (D_0021DD3C != 0) {
        return D_001C2000[4];
    }
    return func_00137FB0();
}
