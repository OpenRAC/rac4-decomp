/* cflags: -mno-split-addresses */
#include "common.h"

extern void *D_0021E070[];
extern u32 D_0021DE98[];

s32 func_L00_007069A0(void) {
    s32 var_a0;
    void *temp_v0;

    temp_v0 = D_0021E070[0];
    var_a0 = 0;
    if (((temp_v0 != NULL) && ((*(u8 *)((s8 *)(temp_v0) + (0x1A9))) == 2)) || ((D_0021DE98[0] - 0x2EU) < 4U)) {
        var_a0 = 1;
    }
    return var_a0;
}
