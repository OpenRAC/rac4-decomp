/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

extern s32 func_01EB6100(void *);
s32 func_01EC22E0(u8 *arg0) {
    if (arg0 == NULL) {
        return 2;
    }
    return func_01EB6100(arg0 + 0x14);
}
