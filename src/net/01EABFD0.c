/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

s32 func_01EABFD0(u32 arg0) {
    if (arg0 > 0xFFFE) {
        return 0;
    }
    return 1;
}
