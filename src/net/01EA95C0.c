/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_0011EFB0(s32);
extern s32 (*D_001681AC)(s32);

s32 func_01EA95C0(s32 *arg0) {
    s32 temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        if (D_001681AC == NULL) {
            func_0011EFB0(temp_a0);
        } else {
            D_001681AC(temp_a0);
        }
        *arg0 = 0;
    }
    return 0;
}
