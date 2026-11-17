/* cflags: @ee32-040921 -O2 -G0 */
#include "common.h"

extern s32 *D_00169548;
extern u32 D_00169544;
s32 func_01EC5248(u32 i) {
    if (D_00169548 == 0) {
        return 0;
    }
    if (i >= D_00169544) {
        return 0;
    }
    return D_00169548[i];
}
