/* Not matched: PAL SCES_532.85.
 * SIZE ours 88 / disc 92 at all 49 physical callable copies.
 * Three existing scalar symbols replace the draft's fixed addresses.
 * Same-program data owners, independent readers and every call/data target
 * were checked without relocation masks. Initial zero is no runtime bound.
 * The no-argument getter and short-circuit reads remain unchanged.
 * The result-copy/common-return join still differs; the final four native
 * bytes are missing. No padding, flag change or emitted data is introduced.
 * Reproduce: python3 tools/check_func.py --version pal func_004CB780 nonmatching/pal/game/func_004CB780.c --diff
 */
#include "common.h"

extern u8 D_0021EE98;
extern s32 D_0021EE54;
extern s32 D_0021EE58;

s32 func_004A3018(void);

s32 func_004CB780(void) {
    s32 var_v1;

    if (D_0021EE98 != 0) {
        return func_004A3018() == 1;
    }
    var_v1 = 0;
    if (D_0021EE54 == 0) {
        var_v1 = D_0021EE58 == 1;
    }
    return var_v1;
}
