/* Call the catalogued PAL overlay helper at 0x70BF98, write 3 into the gp-relative global, and return 1. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

s32 func_L00_007081D8();
extern s32 D_002215CC;

s32 func_L00_00755AB0(void) {
    func_L00_007081D8();
    D_002215CC = 3;
    return 1;
}
