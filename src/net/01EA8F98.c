/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01EA8F98(s32 *arg0) {
    u32 i;

    if (arg0 != NULL) {
        for (i = 0; i < 0x10; i++) {
            if (*arg0++ != 0) {
                return 0;
            }
        }
    }
    return 1;
}
