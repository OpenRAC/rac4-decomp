/* cflags: @ee296 -O2 -G0 -falign-jumps=1 */
#include "common.h"

extern u8 *D_00167F38;
extern s32 *D_001B73D4;

s32 func_01EC98E8(u32 arg0) {
    if (arg0 < *(u32 *)(D_00167F38 + 0x100)) {
        return D_001B73D4[arg0];
    }
    return 0;
}
